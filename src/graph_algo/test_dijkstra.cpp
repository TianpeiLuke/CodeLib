#include "../../include/graph_construct.hpp"
#include "../../include/graph_topology.hpp"


int main(int argc, char* argv[]){

   string filename; 
   if(argc<2)
       filename = "../../data/dijkstraData.txt";
   else
       filename = argv[1];

   unordered_map<int, vector<int>> adjList;
   unordered_map<int, vector<int>> weights;
   unordered_map<int, bool> visited;

   if(!Graph_load_weights(filename, adjList, weights, visited)){
       cout<<"Corrupt file!"<<endl;
       return -1;
   }

   //show_AdjList(adjList);   
   //show_AdjList(weights);
   unordered_map<int, int> min_path;
   int source = 1;
   vector<pair<int, int>> nodeHeap;
   
   cout<<"Compute min-path from source node"<<source<<" to all other nodes ..."<<endl;
   dijkstra(adjList, weights, visited, source, min_path);
   vector<int> queries = {7,37,59,82,99,115,133,165,188,197};
   //answer {2599, 2610, 2947, 2052, 2367, 2399, 2029, 2442, 2505, 3068}

   cout<<endl<<"report results:"<<endl;
   for(auto qnode: queries){
       cout<<"min-path ("<<source<<"->"<<qnode<<") is "<<min_path[qnode]<<endl;
   }

   return 0;
}