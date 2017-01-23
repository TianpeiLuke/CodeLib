#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <sstream>
#include <unordered_map>
#include <ctime> 
#include <cstdlib> 

using namespace std;

void copy_AdjList(const vector<vector<int>*> AdjList, const vector<int> NodeList, vector<vector<int>*>& Copy_AdjList, vector<int>& Copy_NodeList);
void show_AdjList(vector< vector<int>* >& AdjList, int & n);
void read_AdjList(string filename, vector< vector<int>* >& AdjList, vector<int>& NodeList, int & n);
void clean_AdjList(vector< vector<int>* >& AdjList, int& n);
void EdgePick(vector<int>& NodeList, int& node_i, int& node_j, unsigned seed);
void NodeMerge(vector<vector<int>*>& AdjList, int node_i, int node_j);
int CountCrossingEdges(const vector<vector<int>*> AdjList, const int node_i, const int node_j);
int ComputeCut(vector<vector<int>*> AdjList, vector<int> NodeList, int n);
int kargerMinCut(vector<vector<int>*> AdjList, vector<int> NodeList, int n, int& nLoop);





void EdgePick(vector<int>& NodeList, int& node_i, int& node_j, unsigned seed=0){
   srand (seed); // use given seed
   vector<int> NodeList_temp(NodeList.size(),0);
   copy(NodeList.begin(), NodeList.end(), NodeList_temp.begin());
   // random shuffle 
   random_shuffle(NodeList_temp.begin(), NodeList_temp.end());
   node_i = NodeList_temp[0];
   node_j = NodeList_temp[1];
   int i = 1;
   int j = 0;
   // make sure node_i not equal to node_j
   while((node_j == node_i) && i< NodeList_temp.size()){
       i++;
       node_j = NodeList_temp[i];
   }
   if (node_j == node_i){
       cout<<"Merge to one node"<<endl;
       vector<int>::iterator it;
       it = find(NodeList.begin(), NodeList.end(), node_i);
       while(it!= NodeList.end()){
           NodeList.erase(it);                                              
           it = find(NodeList.begin(), NodeList.end(), node_i);
       }
       NodeList.push_back(node_i);
       return;
   }
   // merge node as min(node_i, node_j) and 
   // modify the NodeList so that the repeated node is deleted. 
   int node_merge = min(node_i, node_j);
   if(node_i != node_merge){
       vector<int>::iterator it;
       it = find(NodeList.begin(), NodeList.end(), node_i);
       while(it!= NodeList.end()){
           NodeList.erase(it);
           it = find(NodeList.begin(), NodeList.end(), node_i);
       }
   }
   else if(node_j != node_merge){
       vector<int>::iterator it;
       it = find(NodeList.begin(), NodeList.end(), node_j);
       while(it!= NodeList.end()){
           NodeList.erase(it);
           it = find(NodeList.begin(), NodeList.end(), node_j);             
       }
   }
}

void NodeMerge(vector<vector<int>*>& AdjList,   int node_i, int node_j){
   /*
        Choose the edge node_i-> node_j from AdjList, and merge two nodes into one by changing their names to min(node_i, node_j)
   */
   int n = AdjList.size();
   int node_merge = min(node_i, node_j);
   int i, j;
   for(i=0; i<n; i++){
       //search for node_i 
       if((*AdjList[i])[0] == node_i){
            //merge given node, erase self-loop
            vector<int>::iterator it, it2;
            it = AdjList[i]->begin();
            it ++ ;
            it2 = find(it, AdjList[i]->end(), node_j);
            while(it2!= AdjList[i]->end()){
                AdjList[i]->erase(it2);
                it2 = find(it, AdjList[i]->end(), node_j);
            }
            // rename the vertex as a common name (min(node_i, node_j))
            (*AdjList[i])[0] = node_merge;
       }
       else{
           //  rename the end points if node_j is involved
            for(j=1; j<AdjList[i]->size(); j++){
                 if((*AdjList[i])[j] == node_j) 
                     (*AdjList[i])[j] = node_merge;
            }
      }
   }
   for(i=0; i<n; i++){
       //search for node_j
       if((*AdjList[i])[0] == node_j){
            //merge given node, erase self-loop
            vector<int>::iterator it, it2;
            it = AdjList[i]->begin();
            it ++ ;
            it2 = find(it, AdjList[i]->end(), node_i);
            while(it2!= AdjList[i]->end()){
                AdjList[i]->erase(it2);
                it2 = find(it, AdjList[i]->end(), node_i);
            }
            // rename the vertex as a common name 
            (*AdjList[i])[0] = node_merge;
       }
       else{
            // rename the end point if the node_i is involved
            for(j=1; j<AdjList[i]->size(); j++){
                 if((*AdjList[i])[j] == node_i) 
                     (*AdjList[i])[j] = node_merge;
            }
      }
   }

}

int CountCrossingEdges(const vector<vector<int>*> AdjList, const int node_i,const int node_j){
    int i=0;
    int j=1;
    int count = 0;
    for(i=0; i<AdjList.size(); i++){
         if(AdjList[i]->at(0) == node_i){
             for(j=1; j<AdjList[i]->size(); j++){
                 if(AdjList[i]->at(j) == node_j)
                     count ++;
             }
         }
    }
    return count;
}

int ComputeCut(vector<vector<int>*> AdjList, vector<int> NodeList, int n){
   /*

   */
    unsigned seed = unsigned (time(0)); 
    if(NodeList.empty() || AdjList.empty()) return 0;
    if(NodeList.size() == 1) return 0;
    while(NodeList.size()>2){
       int node_i = NodeList[0];
       int node_j = NodeList[1];
       //Random pick up two nodes in NodeList and merge NodeList
       EdgePick(NodeList, node_i, node_j, seed);
       //Merge edges and nodes in AdjList, then delete self-loops 
       NodeMerge(AdjList, node_i, node_j);
    }
    if(NodeList.size()==2){
       int node_i = NodeList[0];
       int node_j = NodeList[1];
       return CountCrossingEdges(AdjList, node_i, node_j);
    }
    else 
       return 0;
}


int kargerMinCut(vector<vector<int>*> AdjList, vector<int> NodeList, int n, int& nLoop){

   vector<int> results(nLoop, 0);
   int i=0;
   int n_ini = n;
   vector<vector<int>*> AdjList_ini;
   vector<int> NodeList_ini;
   for(i=0; i<nLoop; i++){
      copy_AdjList(AdjList, NodeList, AdjList_ini, NodeList_ini);
      n_ini = n;
      int n_cuts = ComputeCut(AdjList_ini, NodeList_ini, n_ini);
      results[i] = n_cuts;
      cout<<"Loop "<<i<<" NumCuts "<<n_cuts<<" "<<endl;
      clean_AdjList(AdjList_ini, n_ini);
      AdjList_ini.clear();
      NodeList_ini.clear();
   }
   return *min_element(results.begin(), results.end());
}



//=================================================================

void copy_AdjList(const vector<vector<int>*> AdjList, const vector<int> NodeList, vector<vector<int>*>& Copy_AdjList, vector<int>& Copy_NodeList){
    if(!Copy_AdjList.empty()) Copy_AdjList.clear();
    if(!Copy_NodeList.empty()) Copy_NodeList.clear();
    for(int i=0; i<AdjList.size(); i++){
        int size_row = AdjList[i]->size();
        vector<int> * temp = new vector<int> ();
        
        for(auto j=AdjList[i]->begin(); j<AdjList[i]->end(); j++){
           temp->push_back(*j);
        }
        Copy_AdjList.push_back(temp);
    }
    for(int i=0; i<NodeList.size(); i++)
        Copy_NodeList.push_back(NodeList[i]);
}




void show_AdjList(vector< vector<int>* >& AdjList, int & n){
    if(n==0) return;
    for(int i=0; i<n; i++){
        for(auto row=AdjList[i]->begin(); row<AdjList[i]->end(); row++){
           cout<<*row<<" ";
        }
        cout<<endl;
    }
}


void read_AdjList(string filename, vector< vector<int>* >& AdjList, vector<int>& NodeList, int & n){
    int ini_n = AdjList.size();
    if(ini_n >0) AdjList.clear();
    if(!NodeList.empty()) NodeList.clear();
    n = 0;
    ifstream in_stream;
    string line;
    in_stream.open(filename);

    while(getline(in_stream, line)){
        istringstream linestream(line);
        vector<int> *temp = new vector<int>();
        while(!linestream.eof()){
            int temp_data;
            linestream>>temp_data;
            temp->push_back(temp_data);
        }
        AdjList.push_back(temp);
        NodeList.push_back(temp->at(0));
        n ++;
    }
    in_stream.close();
}


void clean_AdjList(vector< vector<int>* >& AdjList, int& n){
    for(int i=AdjList.size()-1; i>=0; i--){
        vector<int> * temp;
        temp = AdjList.back();
        delete temp;
        AdjList.pop_back();
        n--;
    }

}


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

