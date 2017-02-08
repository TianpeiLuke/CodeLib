#include "../../include/graph_topology.hpp"
#include "../../include/graph_construct.hpp"





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




