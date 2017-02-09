#include "../../include/graph_construct.hpp"
#include "../../include/graph_search.hpp"



int main(int argc, char* argv[]){
    string filename;
    int root;
    int target; 
    if(argc<4)
        target = 2;
    else
        target = stoi(argv[3], NULL, 10);

    if(argc<3)
        root = 1;
    else
        root = stoi(argv[2], NULL, 10);

    if(argc<2) 
        filename = "../../data/SCC.txt";
    else
        filename = argv[1];

    unordered_map<int, vector<int>> adjList;
    unordered_map<int, bool> visited;
    if(!Graph_load(filename, adjList, visited)){
        cerr<<"corrupted file"<<endl;
        return -1;
    }else
        cout<<"Success!"<<endl;

    //show_AdjList(adjList); 
    unordered_map<int, vector<int>> adjList_reverse;
    Graph_reverse(adjList, adjList_reverse);
    //show_AdjList(adjList_reverse);

    if(depth_first_search(adjList, root, target, visited))
        cout<<"Find a path from "<<root<<" to "<<target<<endl;
    else cout<<"No path available from "<<root<<" to "<<target<<endl;
    
    // clear visited
    for(auto it=visited.begin(); it!=visited.end(); it++){
         it->second = false;
    }

    if(breadth_first_search(adjList, root, target, visited))
        cout<<"Find a path from "<<root<<" to "<<target<<endl;
    else cout<<"No path available from "<<root<<" to "<<target<<endl;
    return 0;
}
