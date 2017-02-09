#include "../../include/graph_topology.hpp"
#include "../../include/graph_construct.hpp"

void show_edges(const map<pair<int, int>, bool> edge_visit){

    for(auto it=edge_visit.begin(); it!=edge_visit.end(); it++){
        pair<int, int> edge = it->first;
        cout<<"("<<edge.first<<"->"<<edge.second<<")"<<endl;
    }
}

int unique_pair(const map<pair<int, int>, bool> edge_visit){
    int count = 0;
    map<pair<int, int>, bool> temp_visit = edge_visit;
    for(auto it=temp_visit.begin(); it!=temp_visit.end(); it++){
        pair<int, int> edge = it->first;
        pair<int, int> edge_re = make_pair(edge.second, edge.first);
        if(temp_visit[edge] == false || temp_visit[edge_re] == false){
            temp_visit[edge] = true;
            temp_visit[edge_re] = true;
            count ++;
        }
    }
    return count;
}


int rootfind(const int node, const unordered_map<int, int> node_groups){
    //find the root of given node, a unique value for each group
    // takes  O(height) 
    int cur = node;
    int parent = node_groups.at(node);
    while(parent != cur){
        cur = parent;
        parent = node_groups.at(cur);
    }
    return cur;
}

int edgeChange(const unordered_map<int, int> node_groups, map<pair<int, int>, bool>& edge_visit){
    // delete self-loop that connects both nodes within one group
    vector<pair<int, int>> drop_list;
    //map<pair<int, int>, bool> temp;
    for(auto it=edge_visit.begin(); it!=edge_visit.end(); it++){
       pair<int, int> edge = it->first;
       //pair<int, int> edge_re= make_pair(edge.second, edge.first);
       //if(temp[edge] == true || temp[edge_re] == true) continue;
       int node0 = edge.first;
       int node1 = edge.second;
       //bottleneck
       int group1 = rootfind(node0, node_groups);
       int group2 = rootfind(node1, node_groups);
       //cout<<"node"<<node0<<": group"<<group1<<" node"<<node1<<": group"<<group2<<endl;
       if(group1 == group2){
           //drop self-loop
           //temp[edge] = true;
           //temp[edge_re] = true;
           //cout<<"drop self-loop edges" <<endl;
           drop_list.push_back(edge);
           //drop_list.push_back(edge_re);
           //it -- ;
       }
    }
    for(auto edge_temp: drop_list){
       edge_visit.erase(edge_temp);
    }
    return drop_list.size();
}


void nodeMerge(const pair<int, int> edge, unordered_map<int, int>& node_groups){
    /* 
        merge two end points as one, delete the redundant node in node_visit
        by construction, the end point of edge should not all in the same group
    */
    int node0 = edge.first;
    int node1 = edge.second;
    // search the group that contains node0 and that contains node1
    // bottleneck
    int root0 = rootfind(node0, node_groups);
    int root1 = rootfind(node1, node_groups);
    int merge_root = max(root0, root1);
    // take union of two groups
    int add_root = min(root0, root1);
    node_groups[merge_root] = add_root; //ask the root of one tree point to the root of the other tree
    //for(auto it= node_groups.begin(); it!= node_groups.end(); it++){
    //      if(it->second == remove_key){
    //          it->second = new_key;
    //      }
    //}
    // merge groups
}


pair<int, int> edgeRandPick(map<pair<int, int>, bool>& edge_visit){
    // choose one edge in the edgeList randomly and remove it from the list
    
    //srand(seed);
    int displacement = rand() % edge_visit.size();
    int count = 0;
    auto it = edge_visit.begin();
    for(count=0; count<displacement; count++){
        it++;
    }

    pair<int, int> edge1 = make_pair(it->first.first, it->first.second);
    pair<int, int> edge2 = make_pair(it->first.second, it->first.first);
    edge_visit.erase(edge1);     //remove the selected edge
    edge_visit.erase(edge2);
    //cout<<"pick ("<<edge1.first<<","<<edge1.second<<") and ("<<edge2.first<<","<<edge2.second<<")"<<endl;
    if(edge1.first<edge1.second)
       return edge1;
    else
       return edge2;
}


int total_groups(const unordered_map<int, int> node_groups){
    unordered_set<int> group_number;
    for(auto it=node_groups.begin(); it!=node_groups.end(); it++){
        int root = rootfind(it->first, node_groups);
        if(group_number.empty()) group_number.insert(root);
        else if(group_number.find(root) == group_number.end()) 
           group_number.insert(root);
    }
    //for(auto i=group_number.begin(); i!=group_number.end(); i++){
    //     cout<<*i<<" ";
    //}cout<<endl;
    return group_number.size();
}


int computeRandCuts(vector<pair<int, int>>& edgeList){
    /*
        loop over existing edges when edgeList.size() > 1
            e= random pick one edge
            merge(node[e0], node[e1]) into one group
            delete edge within one group
        
    */
    
    unordered_map<int, bool> node_visit;
    edgeList_to_nodeHash(edgeList, node_visit);
    map<pair<int, int>, bool> edge_visit;
    edgeList_hash(edgeList, edge_visit);
    // store the group info for each node
    // node_groups[node] = parent of this node 
    unordered_map<int, int> node_groups;
    for(auto i=node_visit.begin(); i!=node_visit.end(); i++){
         int node = i->first;
         node_groups[node] = node;
    }
    int total_groups_count = total_groups(node_groups);
    //cout<<"Total groups "<<total_groups_count<<endl;
    int count = 0;
    int total_edge = edgeList.size();
    while(edge_visit.size()>1 && total_groups_count >2){
       // ============ a progress bar ==============
       count = count + 2;
       double progress = double(count)/double(total_edge);
       int barWidth = 50;
       cout<<"[";
       int pos = barWidth * progress;
       for(int j=0; j< barWidth; j++){
            if(j<pos) cout<<"=";
            else if(j == pos) cout<<">";
            else cout<<" ";
       }
       cout.precision(3);
       cout<<"]"<<fixed<<int(progress*100.0)<<"%\r";
       cout.flush();
       //=====================================================

       //random pick an edge in the edgeList
       pair<int, int> edge_pick = edgeRandPick(edge_visit);
       //cout<<"Pick edge ("<<edge_pick.first<<"->"<<edge_pick.second<<")"<<endl;
       //merge two end nodes into one group in the given edge
       //cout<<"node merge"<<endl;
       nodeMerge(edge_pick, node_groups);
       //merge edges and delete the self loops
       int count_delta = edgeChange(node_groups, edge_visit); 
       count = count + count_delta;
       //show_edges(edge_visit);

       total_groups_count = total_groups(node_groups);
       //cout<<"Total groups "<<total_groups_count<<endl;
    }
    if(total_groups_count != 2){
       cout<<"Error in computation!"<<endl;
       return -1;
    }
    cout<<endl;
    return unique_pair(edge_visit);
}

int kargerMinCut(const vector<pair<int, int>> edgeList, int max_loop){

    vector<int> results(max_loop, 0); 
    int t =0;
    vector<pair<int, int>> edgeList_t;
    int n_cuts = 0;
    for(t=0; t<max_loop; t++){
        edgeList_t.clear();
        edgeList_t = edgeList;
        n_cuts = 0;
        n_cuts = computeRandCuts(edgeList_t);
        if(n_cuts == -1){
            break;
        }
        results[t] = n_cuts;
        cout.flush();
        cout<<"Loop "<<t<<" NumCuts: "<<n_cuts<<endl;
    }
    if(n_cuts == -1){ cout<<"Error!"<<endl; return -1;}
    return *min_element(results.begin(), results.end());
}


