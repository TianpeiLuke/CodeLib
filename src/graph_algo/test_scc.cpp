#include "../../include/graph_algo/graph_topology.hpp"
#include "../../include/graph_algo/graph_construct.hpp"


int main(int argc, char* argv[]){

   string filename;
   if(argc<2) 
      filename = "../../data/SCC.txt";
   else
      filename = argv[1];

   vector<vector<int>> adjList;
   unordered_map<int, int > nodeloc;
   unordered_map<int, int > nodeIdxMap;
   vector<int> SCC_size;
   //cout<<"Load edge list from "<<filename<<endl;
   if(!Graph_load_edge(filename, adjList, nodeloc)){
       cerr<<"corrupted file"<<endl;
       return -1;
   }
   int verbose = 0;
   if(verbose == 1){
      for(int i=0; i<adjList.size(); i++){
         for(int j=0; j<adjList[i].size(); j++){
            cout<<adjList[i][j]<<" ";
         }
         cout<<endl;
      }
   }
   // 
   cout<<"Compute the strong connected components"<<endl;
   SCC(adjList, nodeloc, SCC_size, verbose);
   

   return 0;
}
