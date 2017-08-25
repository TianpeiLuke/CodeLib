#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

/*

Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
The same repeated number may be chosen from C unlimited number of times.
Note:
- All numbers (including target) will be positive integers.
- The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:

[
  [7],
  [2, 2, 3]
]


*/
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> res;
         vector<int> track;
         if(candidates.empty()) return res;
         sort(candidates.begin(), candidates.end());
         combinationDFS(candidates, target, 0, track, res);
         return res;
}

void combinationDFS(vector<int> candidates, int target, int start, vector<int>& track, vector<vector<int>>& res){
    if(target == 0){
        res.push_back(track);
        return;
    }
    else{
        for(int i=start; i< candidates.size(); i++){
            if(target - candidates[i] >= 0){
                track.push_back(candidates[i]);
                combinationDFS(candidates, target-candidates[i], i, track, res);
                track.pop_back();
            }
        }
    }
}

/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

- All numbers (including target) will be positive integers.
- The solution set must not contain duplicate combinations.

For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,

A solution set is:

[

  [1, 7],

  [1, 2, 5],

  [2, 6],

  [1, 1, 6]

]

*/

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> track;

    if(candidates.empty()) return res;
    sort(candidates.begin(), candidates.end()); //make sure that the duplicates are grouped, also not revisit the same value
    combinationDFS2(candidates, target, 0, track, res);
    return res;
}

void combinationDFS2(vector<int>& candidates, int target, int start,  vector<int>&track, vector<vector<int>>& res ){
    if(target == 0 ){
        res.push_back(track);
        return;
    }else{
        for(int i=start; i<candidates.size(); i++){
            if(target - candidates[i] >= 0){
                if(i> start && candidates[i-1] == candidates[i]) continue; //for duplicates, only one trajectory is pursued
                track.push_back(candidates[i]);
                combinationDFS2(candidates, target - candidates[i], i+1, track, res); //change start = i+1, avoid repetition
                track.pop_back();
            }
        }
    }
}

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example,

If n = 4 and k = 2, a solution is:
[

  [2,4],

  [3,4],

  [2,3],

  [1,2],

  [1,3],

  [1,4],

]

*/

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    if(n==0) return res;
    vector<int> track;
    combineDFS(n, k, 1, track, res);
    return res;
}

void combineDFS(int n, int k, int start, vector<int>& track, vector<vector<int>>& res){
    if(track.size() == k){
        res.push_back(track);
        return;
    }else{
        for(int i=start; i<=n; i++){
            track.push_back(i);
            combineDFS(n, k, i+1, track, res);
            track.pop_back();
        }
    }
}


