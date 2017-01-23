#include "../../include/graph_algo/graph_search.hpp"
#include "../../include/graph_algo/graph_construct.hpp"



void breadth_first_traverse(vector<vector<int>> adjList, int root, vector<bool>& visited, unorderied_map<int, int>& nodeIdxMap){
    /*
        The adjacent list is a vector of vectors, with each row being [source target1, target2, ... ]
        visited[i], indicates if the node (vector index i) is visited
        nodeIdxMap[nodeIdx][vectorIdx] is the map between the graph node index and the vector index i 
    */
    if(adjList.empty()) cerr<<"The input graph is empty !"<<endl;
    int n = adjList.size();
    int rootIdx = -1;
    if(~ visited.empty()) visited.clear();
    visited.assign(n, false);

    if(~ nodeIdxMap.empty()) nodeIdxMap.clear();

    for (int i=0; i<n; i++){
         nodeIdxMap[adjList[i][0]] = i;
         if(adjList[i][0] == root)
             rootIdx = i;
    }

    if(rootIdx == -1) cerr<<"The root node does not exist !"<<endl;

    cout<<"Breadth-First-Search"<<endl;
    queue<int> nodeQueue;
    int nodeIdx = -1;
    int outdegree = 0;
    int childIdx = -1;

    while(rootIdx != -1){
       nodeQueue.push(rootIdx);
       while(~nodeQueue.empty()){
           // pop the front of the queue
           nodeIdx = nodeQueue.front();
           visited[nodeIdx] = true;
           cout<<"Node "<<adjList[nodeIdx][0]<<" visited"<<endl;
           nodeQueue.pop();
           outdegree = adjList[nodeIdx].size();
           // add all non-visited children into the queue
           for(int j=1; j< outdegree; j++){
               childIdx = nodeIdxMap[adjList[nodeIdx][j]];
               if (visited[childIdx] == false)
                  nodeQueue.push(childIdx);
           }
       }
       rootIdx = -1;
       for(int i=0; i<n; i++){
          if(visited[i] == false)
              rootIdx = i;
       }
       if(~nodeQueue.empty()) nodeQueue.clear();
    }

    cout<<"End of BFS search."<<endl;

}


bool breadth_first_search(vector<vector<int>> adjList, int root, int target, vector<bool>& visited,  unordered_map<int, int>& nodeIdxMap){
    /*
        The adjacent list is a vector of vectors, with each row being [source target1, target2, ... ]
        visited[i], indicates if the node (vector index i) is visited
        nodeIdxMap[nodeIdx][vectorIdx] is the map between the graph node index and the vector index i 
    */
    if(adjList.empty()) cerr<<"The input graph is empty !"<<endl;
    if(root == target) return true;
    bool result = false;
    int n = adjList.size();
    int rootIdx = -1;
    if(~ visited.empty()) visited.clear();
    visited.assign(n, false);

    if(~ nodeIdxMap.empty()) nodeIdxMap.clear();

    for (int i=0; i<n; i++){
         nodeIdxMap[adjList[i][0]] = i;
         if(adjList[i][0] == root)
             rootIdx = i;
    }

    if(rootIdx == -1) cerr<<"The root node does not exist !"<<endl;

    cout<<"Breadth-First-Search"<<endl;
    queue<int> nodeQueue;
    int nodeIdx = -1;
    int outdegree = 0;
    int childIdx = -1;
    while(rootIdx != -1){
       nodeQueue.push(rootIdx);
       while(~nodeQueue.empty()){
           // pop the front of the queue
           nodeIdx = nodeQueue.front();
           visited[nodeIdx] = true;
           cout<<"Node "<<adjList[nodeIdx][0]<<" visited"<<endl;
           nodeQueue.pop();
           if(adjList[nodeIdx][0] == target){
                result = true;
                break;
           }
           outdegree = adjList[nodeIdx].size();
           // add all non-visited children into the queue
           for(int j=1; j< outdegree; j++){
               childIdx = nodeIdxMap[adjList[nodeIdx][j]];
               if (visited[childIdx] == false)
                  nodeQueue.push(childIdx);
           }
       }
       if(result == true) break;
       rootIdx = -1;
       for(int i=0; i<n; i++){
          if(visited[i] == false)
              rootIdx = i;
       }
       if(~nodeQueue.empty()) nodeQueue.clear();
    }
    cout<<"End of BFS search."<<endl;
    return result;
}


void main(){
    
    



}
