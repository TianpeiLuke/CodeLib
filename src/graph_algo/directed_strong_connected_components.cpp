#include "../../include/graph_construct.hpp"
#include "../../include/graph_topology.hpp"

void dfs_first_SCC(const unordered_map<int, vector<int>> adjList, int root, unordered_map<int, bool>& visited, unordered_map<int, int>& finishing_time, unordered_map<int, int>& leader, bool verbose=false){
    /*
         The DFS algorithm for the first round of SCC
         computing the finishing_time

         finishing_time is the reverse ordering of the node visited by DFS
    */
    if(root == -1) cerr<<"The root node does not exist !"<<endl;
    if(verbose){ 
       cout<<"Depth-First-Search (reversed graph)"<<endl;
    }
    int leaderSCC = root;     // set the leader of SCC as the root of the new DFS 
    int cur_node;
    int count_size = 0;
    int outdegree = 0;
    int reverse_node;
    int root_time = finishing_time.size(); //using repeatedly 

    // sink node
    if(adjList.at(root).empty()){
       visited[root] = true;
       root_time ++;
       leader[root] = root;
       finishing_time[root] = root_time;
       return;
    }


    stack<int> nodeStack;     // used for depth-first-search
    stack<int> reverseStack;  // used to compute the reverse ordering of the node visited by DFS

    nodeStack.push(root);
    while(!nodeStack.empty()){
        count_size ++;
        // pop the top of the stack
        cur_node = nodeStack.top();
        visited[cur_node] = true;
        nodeStack.pop();
        reverseStack.push(cur_node);             //stack the reversed order
        leader[cur_node] = leaderSCC;            // set the leader of SCC 
        // cout<<"Node "<<adjList[nodeIdx][0]<<" visited"<<endl;
        vector<int> targetList = adjList.at(cur_node);
        outdegree= targetList.size();
        //if(outdegree == 0) continue;
        // push all non-visited children into the stack
        for(auto target: targetList){
            if(visited[target] == false)
                nodeStack.push(target);
        }
    }
    while(!reverseStack.empty()){
        reverse_node = reverseStack.top();
        root_time ++ ;      // count the reverse ordering
        finishing_time[reverse_node] = root_time;
        reverseStack.pop();
    }
    if(verbose){
       cout<<"End of first-DFS loop. size="<<count_size<<endl;
       cout<<endl;
    }
    //return finishing_time;
}

void dfs_second_SCC(const unordered_map<int, vector<int>> adjList, const int root, unordered_map<int, bool>&visited, vector<pair<int, int>>&SCC, unordered_map<int, int>& leader, bool verbose=false){
    /*
         The DFS algorithm for the second round of SCC
         compute the size of SCC
         return SCC_size

         SCC_size[i] store the size of SCC[i] 
         finishing_time[...] to be reset 
         leader[i] record the root of the SCC that contains node i
         
    */
    if(verbose) cout<<"Depth-First-Search (origin graph)"<<endl;
    int SCC_count = 0;
    int leaderSCC = root;     // set the leader of SCC as the root of the new DFS 
    int outdegree = 0;
    int cur_node;
    
    if(adjList.at(root).empty()){
       visited[root] = true;
       SCC_count ++;
       leader[root] = root;
       SCC.push_back(make_pair(root, SCC_count));
       return;
    }

    //dfs
    stack<int> nodeStack;
    nodeStack.push(root);
    while(!nodeStack.empty()){
        // pop the top of the stack
        //cout<<"Size of stack "<<nodeStack.size()<<endl;
        cur_node = nodeStack.top();
        visited[cur_node] = true;
        SCC_count ++;    //count the size of this components
        leader[cur_node] = leaderSCC;           // set the leader of SCC 
        // cout<<"Node "<<adjList[nodeIdx][0]<<" visited"<<endl;
        nodeStack.pop();
        vector<int> targetList = adjList.at(cur_node);
        outdegree = targetList.size();
        //if(outdegree == 0) continue;
        // push all non-visited children into the stack
        for(auto target: targetList){
             if(visited[target] == false) 
                 nodeStack.push(target);
        }
    }
  
    SCC.push_back(make_pair(leaderSCC, SCC_count));
    if(verbose){ 
       cout<<"SCC leader "<<leaderSCC<<", size "<<SCC_count<<endl;
       cout<<"End of second-DFS loop"<<endl;
       cout<<endl;
    }
}


bool any_nonvisited(const unordered_map<int, bool> visited, int& root){
    bool result = false;
    for(auto it=visited.begin(); it!=visited.end(); it++){
        if(it->second == false){
            root = it->first;
            result = true;
            break;
        }
    }
    return result;
}

int count_visited(const unordered_map<int, bool> visited){
    int count = 0;
    for(auto it=visited.begin(); it!=visited.end(); it++){
        if(it->second == true){
            count ++;
        }
    }
    return count;
}


bool CompareSmall(pair<int,int>& x, pair<int,int>& y){
    return x.second < y.second;
}

bool CompareLarge(pair<int,int>& x, pair<int,int>& y){
    return x.second > y.second;
}

vector<pair<int,int>> SCC(unordered_map<int, vector<int>> adjList, unordered_map<int, bool> visited, bool verbose=false){
/*
   using Kosaraju's two-pass algorithm:
  
       1)   Let Grev = G with all arc reversed
  
       2)   run DFS-loop on Grev; compute the "finishing-time" of each node
              finishing-time is an ordering of nodes, indicates the order of visit by DFS

       3)   run DFS-loop on G: discover the SCCs with root given according to the decreasing order of the  "finishing-time" 
*/
       vector<pair<int, int>> SCC;
       unordered_map<int, int> finishing_time;
       finishing_time.clear();
       unordered_map<int, int> leader;  // leader of SCC 
       unordered_map<int, bool> visited_copy = visited;
       unordered_map<int,vector<int>> adjList_reverse;
       // reverse graph
       Graph_reverse(adjList, adjList_reverse);
       if(verbose){
           show_AdjList(adjList_reverse);
       }

       int n = adjList.size();
       int root = n; //begin with far-end point
       // run dfs on reversed graph at first time, find the finishing_time 
       cout<<"Compute finishing_time from reverse graph..."<<endl;
       int count_dfs1 = 1;
       if(verbose) cout<<"Loop "<<count_dfs1<<endl; 

       // if is sink node in reverse graph, process directly 
       int root_time = finishing_time.size();
       if(adjList_reverse.at(root).empty()){
           visited_copy[root] = true;
           root_time ++;
           leader[root] = root;
           finishing_time[root] = root_time;
       }else{
           dfs_first_SCC(adjList_reverse, root, visited_copy, finishing_time, leader, verbose);
       }
       //================ progress bar =============================
       int count_v = count_visited(visited_copy);
       float progress = float(count_v)/float(visited_copy.size());
       int barWidth = 60;
       while(any_nonvisited(visited_copy, root)){
           count_dfs1 ++;
           if(verbose) cout<<"Loop "<<count_dfs1<<endl;
           //=======================================================
           std::cout << "[";
           int pos = barWidth * progress;
           for (int ii = 0; ii < barWidth; ++ii) {
               if (ii < pos) std::cout << "=";
               else if (ii == pos) std::cout << ">";
               else std::cout << " ";
           }
           std::cout << "] " << int(progress * 100.0) << " %"<<" Loop "<<count_dfs1<<"\r";
           std::cout.flush();

           //=================================================================
           // process sink node directly, not to call function
           root_time = finishing_time.size();
           if(adjList_reverse.at(root).empty()){
               visited_copy[root] = true;
               root_time ++;
               leader[root] = root;
               finishing_time[root] = root_time;
           }else{
               dfs_first_SCC(adjList_reverse, root, visited_copy, finishing_time, leader, verbose);
           }
           //================================================================
           count_v = count_visited(visited_copy);
           progress = float(count_v)/float(visited_copy.size());
       }
       // run dfs on original graph at second time, find the SCC
       cout<<endl<<"Compute SCC ..."<<endl;
       SCC.clear();
       leader.clear();
       for(auto it=visited_copy.begin(); it!=visited_copy.end(); it++){
           it->second = false;
       }
       
       //convert finishing time to vector to sort
       vector<pair<int, int>> finishing_vec;
       for(auto it=finishing_time.begin(); it!=finishing_time.end(); it++){
           finishing_vec.push_back(make_pair(it->first, it->second));
           //cout<<"node "<<it->first<<" finishing_time "<<it->second<<endl;
       }
       //sorting in ascending order
       sort(finishing_vec.begin(), finishing_vec.end(), CompareSmall);
       if(verbose){
           for(auto ft: finishing_vec)
               cout<<"("<<ft.first<<": "<<ft.second<<") ";
           cout<<endl;
       }
       //choosing root according to descending order of finishing time
       pair<int, int> elem = finishing_vec.back();
       int root_second = elem.first;
       int count_dfs2 = 1;
       while(!finishing_vec.empty()){
           finishing_vec.pop_back();
           if(verbose) cout<<"Loop "<<count_dfs2<<endl;
           count_dfs2 ++;
           if(verbose){
               cout<<"Root "<<root_second<<" Finishing time "<<elem.second<<endl;
           }
           //=============== progress bar =====================
           count_v = count_visited(visited_copy);
           progress = float(count_v)/float(visited_copy.size());
           cout << "[";
           int pos = barWidth * progress;
           for (int ii = 0; ii < barWidth; ++ii) {
               if (ii < pos) std::cout << "=";
               else if (ii == pos) std::cout << ">";
               else std::cout << " ";
           }
           std::cout << "] " << int(progress * 100.0) << " % "<<" Loop "<<count_dfs2<<"\r";
           std::cout.flush();
           //========================================================
           // process sink node in origin graph directly 
           if(adjList.at(root_second).empty()){
               visited_copy[root_second] = true;
               leader[root_second] = root_second;
               SCC.push_back(make_pair(root_second, 1));
           }else{
               dfs_second_SCC(adjList, root_second, visited_copy, SCC, leader, verbose);
           }
           //choose a root that is not visited
           elem = finishing_vec.back();
           root_second = elem.first;
           while(visited_copy[root_second]==true){
               if(verbose) cout<<root_second<<endl;
               finishing_vec.pop_back();
               if(finishing_vec.empty()) break;
               elem = finishing_vec.back();
               root_second = elem.first;
           }
       }
       cout<<endl;
       if(verbose) cout<<"sorted SCC"<<endl;
       int ss = SCC.size();
       //sorted in decreasing order
       sort(SCC.begin(), SCC.end(), CompareLarge);
       for(int i=0; i< min(5,ss); i++){
           cout<<"Leader "<<SCC[i].first<<" Size: "<<SCC[i].second<<endl;
       }
       return SCC;
}
