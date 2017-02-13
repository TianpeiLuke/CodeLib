#include "../../include/graph_search.hpp"

bool if_all_aug_visited(unordered_map<int, int> visited, int& next){
    bool result = true;
    next = -1;
    for(auto it=visited.begin(); it!=visited.end(); it++){
        if(it->second ==0){
            next = it->first;
            result = false;
            break;
        }
    }
    return result;
}


bool topsort_dfs_routine(const unordered_map<int, vector<int>> adjList, int root, unordered_map<int, int>& aug_visited, stack<int>& reverse_sorted_list, bool verbose=false){
    /*
           topological sorting based on depth-first-search 

        Define an augmented visited map
           three states: 
                        0 = un-visited, 
                        1 = visited-but neigbhors not finished yet
                        2 = visited-all neighbors finished
    */
     //stack<int> path;
     //vector<int> sorted_list_part;
     bool success = true;
     //stack<int> reverse_pop;
     stack<int> tracker;
     tracker.push(root);
     bool all_children_visited = true;
     bool all_temp_visited = false;
     while(!tracker.empty()){
         all_children_visited = true;
         all_temp_visited = false;
         int cur_node = tracker.top();
         if(aug_visited[cur_node] == 0){
             if(verbose) cout<<"visit "<<cur_node<<endl;
             aug_visited[cur_node] = 1;
             //sorted_list.push_back(cur_node);
         }else if(aug_visited[cur_node] == 2){
             tracker.pop(); //redundant node
             continue;
         }
         //not eager to pop yet


         vector<int> neighbors = adjList.at(cur_node); 
         //if(neighbors.empty()){
         //   all_temp_visited = false;
            //leaf, determined 
            //sorted_list_part.push_back(cur_node);
         //   continue;
         //}
         for(auto neighbor : neighbors){
            if(aug_visited[neighbor] == 0){
                tracker.push(neighbor);
                all_children_visited = false;
            }else if(aug_visited[neighbor] == 1){
                all_temp_visited = true;
            }
         }
         if(all_temp_visited){
            cout<<"detect a cycle"<<endl;
            success = false;
            break;
         }
         if(all_children_visited){
            //if all its children is visited-and finished  or it is a leaf, 
            //mark cur_node as visited-all neighbor finished
            aug_visited[cur_node] = 2;
            tracker.pop(); //backtrack to its parent
            reverse_sorted_list.push(cur_node);
            if(verbose) cout<<"mark as black: "<<cur_node<<endl;
         }
     }
     return success;
}

bool topological_sort_dfs(const unordered_map<int, vector<int>> adjList, unordered_map<int, bool>& visited, vector<int>& sorted_list){
    /* 
        Find topological ordering using depth-first search
        
        Define an augmented visited map
           three states: 
                        0 = un-visited, 
                        1 = visited-but neigbhors not finished yet
                        2 = visited-all neighbors finished
    */
    sorted_list.clear();
    bool success = false;
    int root = -1;
    unordered_map<int, int> aug_visited; //add additional state: temp_visited
    for(auto it=visited.begin(); it!= visited.end(); it++){
        aug_visited[it->first] = 0;
    }

    stack<int> reverse_sorted_list;
    while(!if_all_aug_visited(aug_visited, root)){
        success = topsort_dfs_routine(adjList, root, aug_visited, reverse_sorted_list);
        if(success == false){
           sorted_list.clear(); 
           break;
        }
    }
    if(success){
        while(!reverse_sorted_list.empty()){
            int top_black = reverse_sorted_list.top();
            reverse_sorted_list.pop();
            sorted_list.push_back(top_black);
        }
    }
    return success;
}