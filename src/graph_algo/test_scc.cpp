#include "../../include/graph_topology.hpp"
#include "../../include/graph_construct.hpp"


int main(int argc, char* argv[]){
   bool verbose = false;
   if(argc<3)
      verbose = false;
   else
      verbose = bool(stoi(argv[2], NULL, 10));

   string filename;
   if(argc<2) 
      filename = "../../data/SCC.txt";
   else
      filename = argv[1];

   unordered_map<int, vector<int>> adjList;
   unordered_map<int, bool> visited;
   vector<pair<int, int>> SCC_re;
   //cout<<"Load edge list from "<<filename<<endl;
   if(!Graph_load_edges(filename, adjList, visited)){
       cerr<<"corrupted file"<<endl;
       return -1;
   }
   if(verbose){
         show_AdjList(adjList);
   }
   // 
   cout<<"Compute the strong connected components"<<endl;
   SCC_re = SCC(adjList, visited, verbose);
   
  
   vector<int> answer;
   answer = {434821, 968, 459, 313, 211};
   bool is_equal  = false;
   vector<int> result;
   for(auto it=SCC_re.begin(); it!=SCC_re.end(); it++){
        result.push_back(it->second);
   }
   is_equal = equal(result.begin(), result.begin()+5, answer.begin());
   if(is_equal) cout<<"Correct answer !"<<endl;
   else cout<<"Wrong answer !"<<endl;

   return 0;
}
