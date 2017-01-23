#include "../../include/graph_algo/graph_construct.hpp"



bool Graph_load_edge(string filename, vector<vector<int>>& adjList, unordered_map<int, int>& nodeloc ){
/*
    Load edgeList from txt file
    each row is a directed edge [source target] or [tail head]
    
*/
    ifstream infile(filename);
    if(!adjList.empty()) adjList.clear();
    // vector<int> nodeloc;
    nodeloc.clear();
    cout<<"Load edge list from "<<filename<<endl;
    int total_source_size = 0; 
    while(infile){
        string line;
        if(!getline(infile, line)) break;

        istringstream ss(line);
        vector<int> record;
        int vertexIdx = -1;
        int vertexLoc = -1;
        int temp;
        while(ss >> temp){
           //cout<<temp<<" ";
           record.push_back(temp);
        }//cout<<endl;
        // store the source node
        try{
           vertexLoc = nodeloc.at(record[0]);
           // add the target node
           adjList[vertexLoc].push_back(record[1]);
        }catch(const std::out_of_range& oor){
           nodeloc[record[0]] = total_source_size;
           total_source_size ++ ;
           vector<int> new_row; // a new row
           new_row.push_back(record[0]);
           new_row.push_back(record[1]);
           adjList.push_back(new_row);
        }

        try{
           int vertexLoc2 = nodeloc.at(record[1]);
           // add the target node
           // adjList[vertexLoc].push_back(record[1]);
        }catch(const std::out_of_range& oor){
           nodeloc[record[1]] = total_source_size;
           total_source_size ++ ;
           vector<int> new_row2; // a new row
           new_row2.push_back(record[1]);
           //new_row.push_back(record[1]);
           adjList.push_back(new_row2);
        }
    }
    if(!infile.eof()){
       cerr<<"Corrupted file!"<<endl;
       return false;
    }
    cout<<"Total number of rows in adjList: "<<total_source_size<<endl;
    
    return true;
}



void Graph_reverse(const vector<vector<int>> adjList, const unordered_map<int, int> nodeloc,  vector<vector<int>>& adjList_reverse){

    // reverse the edge direction of the graph
    int n = adjList.size();
    if(!adjList_reverse.empty()) adjList_reverse.clear();
    //
    cout<<"Graph initialization ..."<<endl;
    for(int i=0; i<n; i++){
       vector<int> row;
       row.push_back(adjList[i][0]);  //store the same set of nodes
       adjList_reverse.push_back(row);
    }
    int nodeIdx = -1;
    cout<<"Edge reverse"<<endl;
    for(int i=0; i<n; i++){
        for(int j=1; j<adjList[i].size(); j++){
            nodeIdx = nodeloc.at(adjList[i][j]);      //find the row of target node
            adjList_reverse[nodeIdx].push_back(adjList[i][0]); //the index of source node
        }
    }
}



/*
int main(int argc, char* argv[]){
    string filename;
    if(argc < 2)
        filename = "../../data/SCC.txt";
    else
        filename = argv[1];

    vector<vector<int>> adjList; 

    if(Graph_load_edge(filename, adjList)){
         cout<<"Loading sucess!"<<endl;
         int m = adjList.size();
         for(int i=0; i< m; i++){
             int n =  adjList[i].size();
             for(int j=0; j < n; j++){
                cout<<adjList[i][j]<<" ";
             }
             cout<<endl;
         }
    }else
         cout<<"Error"<<endl;
    return 0;
}
*/


