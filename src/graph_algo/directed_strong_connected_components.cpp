#include "../../include/graph_algo/graph_construct.hpp"
#include "../../include/graph_algo/graph_search.hpp"



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
