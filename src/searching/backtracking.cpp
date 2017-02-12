
#include "../../include/searching.hpp"



vector<string> backtracking_dfs(string input, const unordered_map<char, vector<char>> LookUpTable){
   /*
         LookUpTable['1'] = {'a', 'b', 'c','d'}
         LookUpTable['2'] = {'e', 'f'}
         LookUpTable['3'] = {'g', 'h'}
         LookUpTable['4'] = {'i', 'j', 'k', 'l'}
         LookUpTable['5'] = {'m', 'n'}
         LookUpTable['6'] = {'o', 'p', 'q'}
         LookUpTable['7'] = {'r', 's', 't'}
         LookUpTable['8'] = {'u', 'v', 'w'}
         LookUpTable['9'] = {'x', 'y', 'z'}
         LookUpTable['0'] = {' ', '-'}
        
       use depth-first traverse
 
       Note that we use a hash table <int, int> to preserve the pair <input_id, output_id>, such that output = LookUpTable[input[input_id]][output_id]

       Use a stack to keep track of the level number and the path to its parent. 

       Each visit of the same character key in LookUpTable will increase its output_id by 1. When the one round is reached, reset the output_id = 0

      Whenever a new level is reached, add all possible choice (all the children) into stack 
   */
    vector<string> results;
    if(input.empty() || input=="") return results;
    
    //track the <level_number, path to its parent>
    stack<pair<int,string>> path_tracker;
    // <level_number, output_ptr>    
    unordered_map<int, int> ptr_visit; 

    int path_length = input.size();


    // initialize 
    for(int i=0; i< path_length; i++){
       ptr_visit[i] = 0;
    }
    int input_ptr = 0; // input_ptr = current of level number
    int lookup_ptr = 0;  // current lookup output number

    // initialize with all choice in root
    for(int i=0; i<LookUpTable.at(input[input_ptr]).size(); i++)
        path_tracker.push(make_pair(input_ptr, ""));
    
    string cur_path;

    while(!path_tracker.empty()){
        pair<int, string> node = path_tracker.top();
        input_ptr= node.first;
        cur_path = node.second;  //the substring of its parent
        path_tracker.pop();
         
        char cur_char = input[input_ptr];
        lookup_ptr = ptr_visit[input_ptr];        
        //cout<<"visit level "<<input_ptr<<" decoder ptr "<<lookup_ptr<<endl;
        char cur_output = LookUpTable.at(cur_char)[lookup_ptr];
        // visit
        cur_path.push_back(cur_output);
        ptr_visit[input_ptr] ++;
        if(ptr_visit[input_ptr] >= LookUpTable.at(cur_char).size()){
           //out of boundary then reset
           ptr_visit[input_ptr] = 0;
        }
        
        if(input_ptr < path_length -1){
            // go deeper
            int next_input_ptr = input_ptr + 1;
            char next_char = input[next_input_ptr];
            int next_lookup_ptr = ptr_visit[next_input_ptr];
            //cout<<"next level "<<next_input_ptr<<" decoder ptr "<<next_lookup_ptr<<endl;
            if(next_lookup_ptr == 0){
                // store all possible choices with common substring
                for(int i=0; i<LookUpTable.at(next_char).size(); i++)
                    path_tracker.push(make_pair(next_input_ptr, cur_path));
            }
        }
        else{
            results.push_back(cur_path); //finish one path
        }

    }
    return results;
}
