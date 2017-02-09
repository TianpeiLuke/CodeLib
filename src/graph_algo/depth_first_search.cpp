#include "../../include/graph_search.hpp"


//void depth_first_traverse_basic(const vector<vector<int>> adjList, int root, vector<bool>& visited, const unordered_map<int, int> nodeIdxMap){
//    /*
//         The basic DFS algorithm, print the visited node 
//    */
//    if(root == -1) cerr<<"The root node does not exist !"<<endl;
//
//    cout<<"Depth-First-Search"<<endl;
//    stack<int> nodeStack;
//    int nodeIdx = -1;
//    int outdegree = 0;
//    int childIdx = -1;
//    nodeStack.push(root);
//    while(!nodeStack.empty()){
//        // pop the top of the stack
//        //cout<<"Size of stack "<<nodeStack.size()<<endl;
//        nodeIdx = nodeStack.top();
//        visited[nodeIdx] = true;
//        cout<<"Node "<<adjList[nodeIdx][0]<<" visited"<<endl;
//        nodeStack.pop();
//        outdegree = adjList[nodeIdx].size();
//        // push all non-visited children into the stack
//        for(int j=1; j< outdegree; j++){
//            try{
//                childIdx = nodeIdxMap.at(adjList[nodeIdx][j]);
//            }catch(const std::out_of_range& oor){
//                cout<<"Node "<<adjList[nodeIdx][j]<<" dropped"<<endl;
//                continue; //visit a sink node with no out-degree
//            }
//            if (visited[childIdx] == false)
//                nodeStack.push(childIdx);
//        }
//        
//    }
//    cout<<"End of DFS inner-loop"<<endl;
//}
//
//
//bool depth_first_search_basic(const vector<vector<int>> adjList, int root, int target, vector<bool>& visited, const unordered_map<int, int> nodeIdxMap){
//
//    if(root == -1) cerr<<"The root node does not exist !"<<endl;
//
//    cout<<"Depth-First-Search"<<endl;
//    stack<int> nodeStack;
//    int nodeIdx = -1;
//    int outdegree = 0;
//    int childIdx = -1;
//    bool result = false;
//    nodeStack.push(root);
//    while(!nodeStack.empty()){
//         // pop the top of the stack
//        nodeIdx = nodeStack.top();
//        visited[nodeIdx] = true;
//        cout<<"Node "<<adjList[nodeIdx][0]<<" visited"<<endl;
//        nodeStack.pop();
//        if(adjList[nodeIdx][0] == target){
//            result = true;
//            break;
//        }
//        outdegree = adjList[nodeIdx].size();
//        // push all non-visited children into the stack
//        for(int j=1; j< outdegree; j++){
//            try{
//                childIdx = nodeIdxMap.at(adjList[nodeIdx][j]);
//            }catch(const std::out_of_range& oor){
//                cout<<"Node "<<adjList[nodeIdx][j]<<" dropped"<<endl;
//                continue; // visit a sink node with no out-degree
//            }
//            if (visited[childIdx] == false)
//                nodeStack.push(childIdx);
//        }
//    }
//    return result;
//}
//
//void depth_first_traverse(vector<vector<int>> adjList, int root, vector<bool>& visited, unordered_map<int, int>& nodeIdxMap){
//    /*
//        The adjacent list is a vector of vectors, with each row being [source target1, target2, ... ]
//        visited[i], indicates if the node (vector index i) is visited
//        nodeIdxMap[nodeIdx][vectorIdx] is the map between the graph node index and the vector index i 
//    */
//    if(adjList.empty()) cerr<<"The input graph is empty !"<<endl;
//    int n = adjList.size();
//    int rootIdx = -1;
//    if(!visited.empty()) visited.clear();
//    visited.assign(n, false);
//
//    if(!nodeIdxMap.empty()) nodeIdxMap.clear();
//
//    for (int i=0; i<n; i++){
//         nodeIdxMap[adjList[i][0]] = i;
//         if(adjList[i][0] == root)
//             rootIdx = i;
//    }
//
//    if(rootIdx == -1) cerr<<"The root node does not exist !"<<endl;
//
//    //cout<<"Depth-First-Search"<<endl;
//    int nodeIdx = -1;
//    int outdegree = 0;
//    int childIdx = -1;
//    while(rootIdx != -1){
//        // call for basic depth_first_search
//        //cout<<" "<<endl<<endl<<"New start"<<endl;
//        depth_first_traverse_basic(adjList, rootIdx, visited, nodeIdxMap);
//        rootIdx = -1;
//        for(int i=visited.size()-1; i>=0; i--){
//            if(visited[i] == false){
//                rootIdx = i;
//                break;
//            }
//        }
//    }
//    cout<<"End of DFS travese."<<endl;
//
//}
//
//
//
//bool depth_first_search(vector<vector<int>> adjList, int root, int target, vector<bool>& visited, unordered_map<int, int>& nodeIdxMap){
//    /*
//       The adjacent list is a vector of vectors, with each row being [source target1, target2, ... ]
//        visited[i], indicates if the node (vector index i) is visited
//        nodeIdxMap[nodeIdx][vectorIdx] is the map between the graph node index and the vector index i 
//    */
//    if(adjList.empty()) cerr<<"The input graph is empty !"<<endl;
//    if(root == target) return true;
//    bool result = false;
//    int n = adjList.size();
//    int rootIdx = -1;
//    if(!visited.empty()) visited.clear();
//    visited.assign(n, false);
//
//    if(!nodeIdxMap.empty()) nodeIdxMap.clear();
//
//    for (int i=0; i<n; i++){
//        nodeIdxMap[adjList[i][0]] = i;
//        if(adjList[i][0] == root)
//            rootIdx = i;
//    }
//
//    if(rootIdx == -1) cerr<<"The root node does not exist !"<<endl;
//
//    cout<<"Depth-First-Search"<<endl;
//    int nodeIdx = -1;
//    int outdegree = 0;
//    int childIdx = -1;
//    while(rootIdx != -1){
//        cout<<" "<<endl<<endl<<"New start"<<endl;
//        result = depth_first_search_basic(adjList, rootIdx, target, visited, nodeIdxMap);
//        if(result == true) break;
//        rootIdx = -1;
//        for(int i=visited.size()-1; i>=0; i--){
//            if(visited[i] == false){
//                rootIdx = i;
//                break;
//            }
//        }
//    }
//    cout<<"End of DFS search."<<endl;
//    return result;
//
//}

//=======================================================


void depth_first_traverse(const unordered_map<int, vector<int>> adjList, int root, unordered_map<int, bool>& visited){
     /*
        perform DPS using backtracking
    */
    if(root == -1) cerr<<"The root node does not exist !"<<endl;

    cout<<"Depth-First-Search"<<endl;
    stack<int> nodeStack;
    int outdegree = 0;
    nodeStack.push(root);
    while(!nodeStack.empty()){
         // pop the top of the stack
        int cur_node = nodeStack.top();
        visited[cur_node] = true;
        cout<<"Node "<<cur_node<<" visited"<<endl;
        nodeStack.pop();
        vector<int> targetList = adjList.at(cur_node);
        outdegree = targetList.size();
        // push all non-visited children into the stack
        if(outdegree == 0) continue;
        for(auto target: targetList){
            if (visited[target] == false)
                nodeStack.push(target);
        }
    }
    cout<<"Finishing traversing. "<<endl;
}

bool depth_first_search(const unordered_map<int, vector<int>> adjList, int root, int target, unordered_map<int, bool>& visited){
     /*
        perform DPS using backtracking
    */
    if(root == -1) cerr<<"The root node does not exist !"<<endl;

    cout<<"Depth-First-Search"<<endl;
    stack<int> nodeStack;
    int outdegree = 0;
    bool result = false;
    int cur_node;
    nodeStack.push(root);
    while(!nodeStack.empty()){
         // pop the top of the stack
        cur_node = nodeStack.top();
        visited[cur_node] = true;
        cout<<"Node "<<cur_node<<" visited"<<endl;
        nodeStack.pop();
        if(cur_node == target){
            result = true;
            break;
        }
        vector<int> targetList = adjList.at(cur_node);
        outdegree = targetList.size();
        // push all non-visited children into the stack
        if(outdegree == 0) continue;
        for(auto target: targetList){
            if (visited[target] == false)
                nodeStack.push(target);
        }
    }
    return result;
}




