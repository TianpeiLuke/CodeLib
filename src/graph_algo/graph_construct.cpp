#include "../../include/graph_construct.hpp"




//==================================================

bool Graph_load(string filename, vector<vector<int>>& adjList, unordered_map<int, int>& nodeloc ){
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

//===========================================================================
bool Graph_load(string filename, unordered_map<int, vector<int>>& adjList, unordered_map<int, bool>& node_visit ){
/*
    Load adjList from txt file
    assume a undirected graph
    each row is a directed edge [source target1 target2 ...] or [tail head]
    
*/
    ifstream infile(filename);
    adjList.clear();
    // vector<int> nodeloc;
    node_visit.clear();
    int total_node = 0;
    cout<<"Load edge list from "<<filename<<endl;
    while(infile){
        string line;
        if(!getline(infile, line)) break;

        istringstream ss(line);
        vector<int> record;
        int temp;
        while(ss >> temp){
           //cout<<temp<<" ";
           record.push_back(temp);
        }//cout<<endl;
        // store the source node
        try{
           bool visit = node_visit.at(record[0]);
           // add the target node
           for(int i=1; i<record.size(); i++){
               adjList[record[0]].push_back(record[i]);
           }
        }catch(const std::out_of_range& oor){
           node_visit[record[0]] = false;
           
           vector<int> new_row; // a new row
           //new_row.push_back(record[0]);
           for(int i=1; i<record.size(); i++) new_row.push_back(record[i]);
           adjList[record[0]] = new_row;
           total_node ++;
        }
        for(int i=1; i<record.size(); i++){
           try{
               bool visit = node_visit.at(record[i]);
           // add the target node
           // adjList[vertexLoc].push_back(record[1]);
           }catch(const std::out_of_range& oor){
               node_visit[record[i]] = false;
               vector<int> new_row2; // a new row
               new_row2.clear();
               //new_row.push_back(record[1]);
               adjList[record[i]] = new_row2; //empty vector
               total_node ++;
           }
        }
    }
    if(!infile.eof()){
       cerr<<"Corrupted file!"<<endl;
       return false;
    }
    cout<<"Total number of rows in adjList: "<<total_node<<endl;
    
    return true;
}

void Graph_reverse(const unordered_map<int, vector<int>> adjList, unordered_map<int, vector<int>>& adjList_reverse){
    // reverse the edge direction of the graph
    int n = adjList.size();
    if(!adjList_reverse.empty()) adjList_reverse.clear(); 
    //
    cout<<"Graph initialization ..."<<endl;
    for(auto i=adjList.begin(); i!=adjList.end(); i++){
       int node = i->first;
       vector<int> row;
       row.clear();
       adjList_reverse[node] = row;
    }
    cout<<"Edge reverse"<<endl;
    for(auto i=adjList.begin(); i!=adjList.end(); i++){
       vector<int> row = i->second;
       int node = i->first;
       for(auto target: row)
            adjList_reverse[target].push_back(node); //the index of source node 
    }
}

void copy_AdjList(const unordered_map<int, vector<int>> adjList, unordered_map<int, vector<int>>& copy_adjList){
    // do a deep copy
    if(!copy_adjList.empty()) copy_adjList.clear();

    for(auto i=adjList.begin(); i!=adjList.end(); i++){
        vector<int> row = i->second;
        int node = i->first;
        vector<int> new_row(row.size(), 0);
        copy(row.begin(), row.end(), new_row.begin());
        copy_adjList[node] = new_row;
    }

}

void show_AdjList(const unordered_map<int, vector<int>> adjList){
    for(auto i=adjList.begin(); i!=adjList.end(); i++){
        vector<int> row = i->second;
        int node = i->first;
        cout<<node<<": ";
        for(auto target: row){
           cout<<target<<" ";
        }
        cout<<endl;
    }
}

void adjList_to_nodeList(const unordered_map<int, vector<int>> adjList, vector<int>& nodeList){
    if(!nodeList.empty()) nodeList.clear();
    vector<pair<int, int>> edgeList;
    adjList_to_edgeList(adjList, edgeList);
    edgeList_to_nodeList(edgeList, nodeList); //maintain the order
//    for(auto i=adjList.begin(); i<adjList.end(); i++){
//        int node = i->first;
//        nodeList.push_back(node);
//    }
}

void nodeList_hash(const vector<int> nodeList, unordered_map<int, bool>& node_visit){
    for(auto node: nodeList){
        node_visit[node] = false;
    }
}

void adjList_to_edgeList(const unordered_map<int, vector<int>> adjList, vector<pair<int, int>>& edgeList){
    if(!edgeList.empty()) edgeList.clear();
    for(auto i=adjList.begin(); i!=adjList.end(); i++){
        vector<int> row = i->second;
        int node = i->first;
        if(row.empty()) continue;
        for(auto target: row){
           pair<int, int> edge;
           edge = make_pair(node, target);
           edgeList.push_back(edge);
        }
    }
}

void edgeList_hash(const vector<pair<int, int>> edgeList, map<pair<int, int>, bool>& edge_visit){
    if(!edge_visit.empty()) edge_visit.clear();
    for(auto edge: edgeList){
       edge_visit[edge] = false;
    }
}

void edgeHash_keyList(const map<pair<int, int>, bool> edge_visit, vector<pair<int, int>>& edgeList){
    edgeList.clear();
    for(auto it = edge_visit.begin(); it!=edge_visit.end(); it++){
          edgeList.push_back(it->first);
    }
}

void edgeList_to_nodeList(const vector<pair<int, int>> edgeList, vector<int>& nodeList){
    if(!nodeList.empty()) nodeList.clear();
    unordered_map<int, bool> node_visit;
    for(auto edge: edgeList){
       node_visit[edge.first] = false;
       node_visit[edge.second] = false;
    }
    for(auto it= node_visit.begin(); it!=node_visit.end(); it++){
       nodeList.push_back(it->first);
    }
}

void edgeList_to_nodeHash(const vector<pair<int, int>> edgeList, unordered_map<int, bool>& node_visit){
    if(!node_visit.empty()) node_visit.clear();
    for(auto edge: edgeList){
       node_visit[edge.first] = false;
       node_visit[edge.second] = false;
    }
}

void show_edgeList(const vector<pair<int,int>> edgeList){
    for(auto edge: edgeList){
       cout<<edge.first<<"->"<<edge.second<<endl;
    }
}
//==========================================================================

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


