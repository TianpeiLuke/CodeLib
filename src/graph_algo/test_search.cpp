#include "../../include/graph_algo/graph_construct.hpp"
#include "../../include/graph_algo/graph_search.hpp"



int main(int argc, char* argv[]){
    string filename;
    if(argc<2) 
       filename = "../../data/SCC.txt";
    else
       filename = argv[1];

    vector<vector<int>> adjList;
    unordered_map<int, int> nodeloc;
    //cout<<"Load edge list from "<<filename<<endl;
    //bool flag = Graph_load_edge(filename, adjList);
    //cout<<"Flag "<<flag<<endl;
    if(!Graph_load_edge(filename, adjList, nodeloc)){
        cerr<<"corrupted file"<<endl;
        return -1;
    }
    for(int i=0; i< adjList.size(); i++){
        for(int j=0; j< adjList[i].size(); j++)
           cout<<adjList[i][j]<<" ";
        cout<<endl;
    }
    vector<vector<int>> adjList_reverse;
    Graph_reverse(adjList, nodeloc, adjList_reverse);
    for(int i=0; i< adjList_reverse.size(); i++){
        for(int j=0; j< adjList_reverse[i].size(); j++)
           cout<<adjList_reverse[i][j]<<" ";
        cout<<endl;
    }

    vector<bool> visited;
    unordered_map<int, int> nodeIdxMap;
    int root = 1;
    int target = 2;
    //if(depth_first_search(adjList, root, target, visited, nodeIdxMap))
    //   cout<<"Find a path from "<<root<<" to "<<target<<endl;
    //else
    //   cout<<"Lost."<<endl;
    depth_first_traverse(adjList, root, visited, nodeIdxMap);

    return 0;
}
