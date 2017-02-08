/*
 Remove Invalid Parentheses

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]

*/

#include "../../include/graph_search.hpp"

bool check(string s){

    // check if the string contain a valid parentheses, 
    int count_pair = 0;

    for(auto c: s){
        if(c=='('){
            count_pair ++;
        }
        else if(c==')'){
            count_pair --;
            if(count_pair<0) return false;
        }
    }
    return (count_pair == 0);
}





vector<string> removeInvalidParentheses(string s) {
    vector<string> result;
    if(s.empty()){
        result.push_back("");
        return result;
    } 

    if(check(s)){
        result.push_back(s);
        return result;
    }



    int remove_left = 0;
    int remove_right = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') remove_left ++;
        else if(s[i] == ')'){
            if(remove_left >0) remove_left --;
            else remove_right ++;
        }
    }

    //{remove_left, remove_right, current_level}

    vector<int> remove_left_right_level = {remove_left, remove_right, 0};

    stack<pair<vector<int>, string>> dfs_path;
    // use depth-first-search, record the visit status of checked node
    dfs_path.push(make_pair(remove_left_right_level, s));

    //record the visit status
    unordered_map<string, bool> visit; 
    visit[s] = true;

    int max_level = s.size();

    while(!dfs_path.empty()){
        vector<int> temp_vec = dfs_path.top().first;
        string temp_str = dfs_path.top().second;
        bool visit_cur = visit[temp_str];
        int level_cur = temp_vec[2];
        if(!visit_cur){
            // if visit, see if valid
            visit[temp_str] = true;
            if(temp_str =="" || level_cur > max_level){
                dfs_path.pop();
            }else{
                if(check(temp_str) && level_cur == max_level){ 
                    result.push_back(temp_str); //store valid
                    dfs_path.pop(); // back to its root, see its brother (since only need the least change)
                }else if(check(temp_str) && level_cur < max_level){
                    max_level = level_cur; 
                    result.clear(); // a new level set so clear the past history
                    result.push_back(temp_str); //store valid
                    dfs_path.pop(); 
                }
            } 
        }else{ // visited so not valid
            bool flag = true; //if all children visited 
            if(temp_vec[0] >0){
                //remove "("
                for(int i=0; i<temp_str.size(); i++){
                    if(temp_str[i] == '('){
                        string temp_tempstr = temp_str;
                        temp_tempstr.erase(temp_tempstr.begin()+i);
                        // assign value for all child if first seen
                        try {
                             bool ifvisit = visit.at(temp_tempstr);      
                        }
                        catch (const std::out_of_range& oor) {
                             visit[temp_tempstr] = false;
                        }
                        if(!visit[temp_tempstr]){
                            temp_str = temp_tempstr;
                            temp_vec[0] --;
                            temp_vec[2] ++;
                            flag = false;
                            break;
                        }
                    }
                }
            }else if(temp_vec[1] > 0){
                //remove ")"
                for(int i=0; i<temp_str.size(); i++){
                    if(temp_str[i] == ')'){
                        string temp_tempstr = temp_str;
                        temp_tempstr.erase(temp_tempstr.begin()+i);
                        // assign value for all child
                        try {
                             bool ifvisit = visit.at(temp_tempstr);      // vector::at throws an out-of-range
                        }
                        catch (const std::out_of_range& oor) {
                             visit[temp_tempstr] = false;
                        }
                        if(!visit[temp_tempstr]){
                            temp_str = temp_tempstr;
                            temp_vec[1] --;
                            temp_vec[2] ++;
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if(!flag){
                vector<int> temp_tempvec = temp_vec;
                dfs_path.push(make_pair(temp_tempvec, temp_str));
            }
            else dfs_path.pop(); //when all children visited 
        }
    }
    if(result.empty()) result.push_back("");
    return result;
}

