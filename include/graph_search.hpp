#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <string>
#include <climits>
#include <utility>

#ifndef _GRAPH_ALGO_SEARCH
#define _GRAPH_ALGO_SEARCH

#ifndef _NAMESPACE
#define _NAMESPACE
using namespace std;
#endif

// breadth_first_search
void breadth_first_traverse(vector<vector<int>> adjList, int root, vector<bool>& visited, unordered_map<int, int>& nodeIdxMap );


void breadth_first_search(vector<vector<int>> adjList, int root, int target, vector<bool>& visited, unordered_map<int, int>& nodeIdxMap );

// depth_first_search

 //void depth_first_traverse_basic(vector<vector<int>>& adjList, int& root, vector<bool>& visited, unordered_map<int, int>& nodeIdxMap );
 //
 //bool depth_first_search_basic(const vector<vector<int>> adjList, int root, int target, vector<bool>& visited, unordered_map<int, int>& nodeIdxMap );
 //
void depth_first_traverse(vector<vector<int>> adjList, int root, vector<bool>& visited, unordered_map<int, int>& nodeIdxMap );


bool depth_first_search(vector<vector<int>> adjList, int root, int target, vector<bool>& visited, unordered_map<int, int>& nodeIdxMap );


//void depth_first_traverse_basic_SCC(const vector<vector<int>> adjList, int root, int& root_time,  vector<int>& finishing_time, vector<int>& leader,  vector<bool>& visited, const unordered_map<int, int> nodeIdxMap);



// Remove Invalid Parentheses
bool check(string s);

vector<string> removeInvalidParentheses(string s);

#endif