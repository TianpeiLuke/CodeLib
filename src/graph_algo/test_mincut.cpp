#include "../../include/graph_topology.hpp"
#include "../../include/graph_construct.hpp"

int main(int argc, const char * argv[]){
   bool test = true;
   if(argc< 4)
       test = true;
   else
       test = bool(stoi(argv[3], NULL, 10));
   
   int nLoop = 20;
   if(argc < 3)
       nLoop = 20;
   else    
       nLoop = stoi(argv[2], nullptr, 10);

   string filename;
   if(argc<2)
      filename = "../../data/kargerMinCut.txt";
   else
      filename = argv[1];

   if(!test){
       cout<<"Read file "<<filename<<"..."<<endl;
       //vector<vector<int>*> AdjList;
       unordered_map<int, vector<int>> adjList;
       unordered_map<int, bool> node_visit;
       vector<int> nodeList;
       int n = 0;
       // load graph in adjList
       if(!Graph_load(filename, adjList, node_visit)){
            cout<<"cannot load graph!"<<endl;
            return -1;
       }
       //convert to edgeList
       //show_AdjList(adjList);
       vector<pair<int, int>> edgeList;
       adjList_to_edgeList(adjList, edgeList);
       //show_edgeList(edgeList);
       //read_AdjList(filename, AdjList, NodeList, n);
       cout<<"Number of vertices: "<<adjList.size()<<endl;
       cout<<"Compute Min-Cut"<<endl;
       int nLoop = 23;
       int min_cut = 0;
       min_cut = kargerMinCut(edgeList, nLoop);
       cout<<"Final result: "<<endl;
       cout<<"Loop "<<nLoop<<" Min-Cut: "<<min_cut<<endl;
   }
   else{
       unordered_map<int, vector<int>> adjList; 
       vector<int> node_1 = {2,3};
       //node_1.push_back(2);
       //node_1.push_back(3);
       adjList[1] = node_1;
       vector<int> node_2 = {1,3,4};
       //node_2.push_back(1);
       //node_2.push_back(3);
       //node_2.push_back(4);
       adjList[2] = node_2;
       vector<int> node_3 = {1,2};
       //node_3.push_back(1);
       //node_3.push_back(2);
       adjList[3] = node_3;
       vector<int> node_4 = {2,5,6};
       //node_4.push_back(2);
       //node_4.push_back(5);
       //node_4.push_back(6);
       adjList[4] = node_4;
       vector<int> node_5 = {4, 6};
       //node_5.push_back(4);
       //node_5.push_back(6);
       adjList[5] = node_5;
       vector<int> node_6 = {4, 5};
       //node_6.push_back(4);
       //node_6.push_back(5);
       adjList[6] = node_6;
       vector<pair<int, int>> edgeList;
       adjList_to_edgeList(adjList, edgeList);
       cout<<"Number of vertices: "<<adjList.size()<<endl;
       show_edgeList(edgeList);
       cout<<"Compute Min-Cut"<<endl;
       int nLoop = 50;
       int min_cut = 0;
       min_cut = kargerMinCut(edgeList, nLoop);
       cout<<"Final result: "<<endl;
       cout<<"Loop "<<nLoop<<" Min-Cut: "<<min_cut<<endl;
   }
}

