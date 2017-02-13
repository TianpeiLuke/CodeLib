#include "../../include/graph_construct.hpp"
#include "../../include/graph_search.hpp"

int main(int argc, char* argv[]){

    string filename;
    if(argc < 2){
       filename = "../../data/topsort.txt";
    }
    else filename = argv[1];
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, bool> visited;
    cout<<"Load graph "<<endl;
    if(!Graph_load(filename, adjList, visited)){
        cerr<<"Fail to load graph"<<endl;
        return -1;
    }

    vector<int> sorted_list;
    if(!topological_sort_dfs(adjList, visited, sorted_list )){
        cerr<<"Not Directed Acyclic Graph ! "<<endl;
        return -1;
    }
    cout<<"Topological sorted list of nodes "<<endl;
    for(auto elem: sorted_list){
        cout<<elem<<" ";
    }cout<<endl;



    return 0;
}
