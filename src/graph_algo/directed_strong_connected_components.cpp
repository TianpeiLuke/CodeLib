#include "../../include/graph_construct.hpp"
#include "../../include/graph_topology.hpp"

void depth_first_traverse_SCC_r1(const vector<vector<int>> adjList, int root, int& root_time, vector<int>& finishing_time, vector<int>& leader,  vector<bool>& visited, const unordered_map<int, int> nodeIdxMap){
    /*
         The DFS algorithm for the first round of SCC
         computing the finishing_time

         finishing_time is the reverse ordering of the node visited by DFS
    */
    if(root == -1) cerr<<"The root node does not exist !"<<endl;

    cout<<"Depth-First-Search"<<endl;
    stack<int> nodeStack;     // used for depth-first-search
    stack<int> reverseStack;  // used to compute the reverse ordering of the node visited by DFS

    int leaderSCC = root;     // set the leader of SCC as the root of the new DFS 

    int nodeIdx = -1;
    int outdegree = 0;
    int childIdx = -1;
    nodeStack.push(root);
    while(!nodeStack.empty()){
        // pop the top of the stack
        //cout<<"Size of stack "<<nodeStack.size()<<endl;
        nodeIdx = nodeStack.top();
        visited[nodeIdx] = true;
        reverseStack.push(nodeIdx);             //stack the reversed order
        leader[nodeIdx] = leaderSCC;            // set the leader of SCC 
        // cout<<"Node "<<adjList[nodeIdx][0]<<" visited"<<endl;
        nodeStack.pop();
        outdegree = adjList[nodeIdx].size();
        // push all non-visited children into the stack
        for(int j=1; j< outdegree; j++){
            try{
                childIdx = nodeIdxMap.at(adjList[nodeIdx][j]);
            }catch(const std::out_of_range& oor){
                cout<<"Node "<<adjList[nodeIdx][j]<<" dropped"<<endl;
                continue; //visit a sink node with no out-degree
            }
            if (visited[childIdx] == false)
                nodeStack.push(childIdx);
        }
        
    }

    int reverseIdx = -1;
    while(!reverseStack.empty()){
        reverseIdx = reverseStack.top();
        root_time ++ ;      // count the reverse ordering
        finishing_time[reverseIdx] = root_time;
        reverseStack.pop();
        //cout<<"Finishing time of "<<adjList[reverseIdx][0]<<": "<<root_time<<endl;
    }
    cout<<"End of DFS inner-loop"<<endl;
}


void depth_first_SCC(vector<vector<int>> adjList, int root, vector<bool>& visited, vector<int>& finishing_time, vector<int>&leader,  unordered_map<int, int>& nodeIdxMap){
    /*
        The first round of SCC algorithm 
        The adjacent list is a vector of vectors, with each row being [source target1, target2, ... ]
        visited[i], indicates if the node (vector index i) is visited
        nodeIdxMap[nodeIdx][vectorIdx] is the map between the graph node index and the vector index i 
        finishing_time[i] is the reversed order of node index visited by DFS
        leader[i] is the root node of cluster containing node i by DFS 
        
        call depth_first_traverse_SCC_r1() 
    */
    if(adjList.empty()) cerr<<"The input graph is empty !"<<endl;
    int n = adjList.size();
    int rootIdx = -1;
    if(!visited.empty()) visited.clear();
    visited.assign(n, false);
    if(!finishing_time.empty()) finishing_time.clear();
    finishing_time.assign(n, -1);
    if(!leader.empty()) leader.clear();
    leader.assign(n, -1);

    if(!nodeIdxMap.empty()) nodeIdxMap.clear();

    for (int i=0; i<n; i++){
         nodeIdxMap[adjList[i][0]] = i;
         if(adjList[i][0] == root)
             rootIdx = i;
    }

    if(rootIdx == -1) cerr<<"The root node does not exist !"<<endl;

    

    //cout<<"Depth-First-Search"<<endl;
    int nodeIdx = -1;
    int outdegree = 0;
    int childIdx = -1;
    int count = 0;
    int timer  = 0;
    while(rootIdx != -1){
        // call for basic depth_first_search
        //cout<<" "<<endl<<endl<<"New start"<<endl;
        cout<<(count++)<<"-th call of DFS"<<endl;
        depth_first_traverse_SCC_r1(adjList, rootIdx, timer, finishing_time, leader,  visited, nodeIdxMap);
        rootIdx = -1;
        for(int i=visited.size()-1; i>=0; i--){
            if(visited[i] == false){
                rootIdx = i;
                // cout<<"Pick "<<adjList[i][0]<<endl;
                break;
            }
        }
    }
    cout<<"End of finishing_time computation."<<endl;

}


void depth_first_traverse_SCC_r2(const vector<vector<int>> adjList, const int root, vector<int>& finishing_time, vector<int>& leader, vector<int>& SCC_size, vector<bool>& visited, const unordered_map<int, int> nodeIdxMap){
    /*
         The DFS algorithm for the second round of SCC
         compute the size of SCC
         
         SCC_size[i] store the size of SCC[i] 
         finishing_time[...] to be reset 
         leader[i] record the root of the SCC that contains node i
    */
    if(root == -1) cerr<<"The root node does not exist !"<<endl;

    cout<<"Depth-First-Search"<<endl;
    stack<int> nodeStack;
    stack<int> reverseStack;  // used to store all visited nodes

    int leaderSCC = root;     // set the leader of SCC as the root of the new DFS 

    int nodeIdx = -1;
    int outdegree = 0;
    int childIdx = -1;
    nodeStack.push(root);
    while(!nodeStack.empty()){
        // pop the top of the stack
        //cout<<"Size of stack "<<nodeStack.size()<<endl;
        nodeIdx = nodeStack.top();
        visited[nodeIdx] = true;
        reverseStack.push(nodeIdx);            // record the trejactory
        leader[nodeIdx] = leaderSCC;           // set the leader of SCC 
        // cout<<"Node "<<adjList[nodeIdx][0]<<" visited"<<endl;
        nodeStack.pop();
        outdegree = adjList[nodeIdx].size();
        // push all non-visited children into the stack
        for(int j=1; j< outdegree; j++){
            try{
                childIdx = nodeIdxMap.at(adjList[nodeIdx][j]);
            }catch(const std::out_of_range& oor){
                continue; //visit a sink node with no out-degree
            }
            if (visited[childIdx] == false)
                nodeStack.push(childIdx);
        }
        
    }

    int reverseIdx = -1;
    int SCC_count = 0;
    while(!reverseStack.empty()){
        reverseIdx = reverseStack.top();
        SCC_count ++ ;             // count the size of strong connected component
        finishing_time[reverseIdx] = INT_MIN; // record the path by resetting the finishing time 
        reverseStack.pop();
    }
    SCC_size.push_back(SCC_count);
    cout<<"SCC leader "<<leaderSCC<<", size "<<SCC_count<<endl;
    cout<<"End of DFS inner-loop"<<endl;
}

void depth_second_SCC(const vector<vector<int>> adjList, const unordered_map<int, int> nodeIdxMap, const vector<int> finishing_time,  vector<int>& leader, vector<int>& SCC_size, vector<bool>& visited){
/*
       The second round of SCC algorithm
       set the root of DFS according to finishing time (from large to small)
       call depth_first_traverse_SCC_r2, resetting the finishing_time, and leader 
            then compute the size of SCC

*/

    if(adjList.empty()) cerr<<"The input graph is empty !"<<endl;
    int n = adjList.size();
    int rootIdx = -1;
    // reset the visited flag
    if(!visited.empty()) visited.clear();
    visited.assign(n, false);
    if(!leader.empty()) leader.clear();
    leader.assign(n, -1);
    vector<int> copy_finishing_time(n, -1);
    copy(finishing_time.begin(), finishing_time.end(), copy_finishing_time.begin());
    
    int max_idx = n;

    max_idx = max_element(copy_finishing_time.begin(), copy_finishing_time.end()) - copy_finishing_time.begin();
    while(copy_finishing_time[max_idx] != INT_MIN){
        // let the root be the maximum finishing time in reversed graph
        rootIdx = max_idx;
        depth_first_traverse_SCC_r2(adjList, rootIdx, copy_finishing_time, leader, SCC_size,  visited, nodeIdxMap);
    
        max_idx = max_element(copy_finishing_time.begin(), copy_finishing_time.end()) - copy_finishing_time.begin();

    }
    
    cout<<"End of SCC computation"<<endl;
}


void SCC(vector<vector<int>> adjList, unordered_map<int, int> nodeloc,  vector<int>& SCC_size, int verbose=0){
/*
   using Kosaraju's two-pass algorithm:
  
       1)   Let Grev = G with all arc reversed
  
       2)   run DFS-loop on Grev; compute the "finishing-time" of each node
              finishing-time is an ordering of nodes, indicates the order of visit by DFS

       3)   run DFS-loop on G: discover the SCCs with root given according to the decreasing order of the  "finishing-time" 
*/
       unordered_map<int, int> nodeIdxMap;
       //unordered_map<int, int> nodeloc;
       vector<int> finishing_time;
       vector<int> leader;  // leader of SCC 
       vector<bool> visited;
       vector<vector<int>> adjList_reverse;
       // reverse graph
       Graph_reverse(adjList, nodeloc, adjList_reverse);
       if(verbose == 1){
          for(int i=0; i<adjList_reverse.size(); i++){
             for(int j=0; j<adjList_reverse[i].size(); j++){
                cout<<adjList_reverse[i][j]<<" ";
             }
             cout<<endl;
          }
       }
       int n = adjList.size();
       int root = n;
       // run dfs on reversed graph at first time, find the finishing_time 
       cout<<"Compute finishing_time ..."<<endl;
       depth_first_SCC(adjList_reverse, root, visited, finishing_time, leader, nodeIdxMap);
       // run dfs on original graph at second time, find the SCC
       cout<<"Compute SCC ..."<<endl;
       SCC_size.clear();
       depth_second_SCC(adjList, nodeIdxMap, finishing_time, leader, SCC_size, visited);
       cout<<"SCC size"<<endl;
       int ss = SCC_size.size();
       for(int i=0; i< ss; i++){
         cout<<SCC_size[i]<<endl;
       }
       cout<<"Sorted SCC size:"<<endl;
       sort(SCC_size.begin(), SCC_size.end(), std::greater<int>());
       for(int i=0; i< min(5,ss); i++){
         cout<<SCC_size[i]<<endl;
       }
}
