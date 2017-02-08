#include "../../include/graph_topology.hpp"
#include "../../include/graph_construct.hpp"

int main(int argc, const char * argv[]){
   
   string filename = argv[1];
   bool test = bool(strtol(argv[2], NULL, 10));
   if(!test){
       cout<<"Read file "<<filename<<"..."<<endl;
       vector<vector<int>*> AdjList;
       vector<int> NodeList;
       int n = 0;
       read_AdjList(filename, AdjList, NodeList, n);
       cout<<"Number of vertices: "<<AdjList.size()<<endl;
       cout<<"Compute Min-Cut"<<endl;
       int nLoop = 100000;
       int min_cut = 0;
       min_cut = kargerMinCut(AdjList, NodeList, n, nLoop);
       cout<<"Final result: "<<endl;
       cout<<"Loop "<<nLoop<<" Min-Cut: "<<min_cut<<endl;
       cout<<"Clear data"<<endl;
       clean_AdjList(AdjList, n);
   }
   else{
       vector<vector<int>*> AdjList; 
       vector<int>* node_1 = new vector<int>();
       node_1->push_back(1);
       node_1->push_back(2);
       node_1->push_back(3);
       vector<int>* node_2 = new vector<int>();
       node_2->push_back(2);
       node_2->push_back(1);
       node_2->push_back(3);
       node_2->push_back(4);
       vector<int>* node_3 = new vector<int>();
       node_3->push_back(3);
       node_3->push_back(1);
       node_3->push_back(2);
       vector<int>* node_4 = new vector<int>();
       node_4->push_back(4);
       node_4->push_back(2);
       node_4->push_back(5);
       node_4->push_back(6);
       vector<int>* node_5 = new vector<int>();
       node_5->push_back(5);
       node_5->push_back(4);
       node_5->push_back(6);
       vector<int>* node_6 = new vector<int>();
       node_6->push_back(6);
       node_6->push_back(4);
       node_6->push_back(5);
       AdjList.push_back(node_1);
       AdjList.push_back(node_2);
       AdjList.push_back(node_3);
       AdjList.push_back(node_4);
       AdjList.push_back(node_5);
       AdjList.push_back(node_6);
       vector<int> NodeList = {1,2,3,4,5,6};
       int n = 6;
       cout<<"Number of vertices: "<<AdjList.size()<<endl;
       cout<<"Compute Min-Cut"<<endl;
       int nLoop = 32;
       int min_cut = 0;
       min_cut = kargerMinCut(AdjList, NodeList, n, nLoop);
       cout<<"Final result: "<<endl;
       cout<<"Loop "<<nLoop<<" Min-Cut: "<<min_cut<<endl;
       cout<<"Clear data"<<endl;
       clean_AdjList(AdjList, n);
   /*vector<int> a = {1, 1, 1 , 1, 2};
   vector<int>::iterator it, it2;
   int s = 1;
   it = a.begin();
   it ++ ;
   it2 = find(it, a.end(), s);
   while(it2!= a.end()){
      a.erase(it2);
      it2 = find(it, a.end(), s);
   }
   cout<<a.size()<<endl;*/
   }
}

