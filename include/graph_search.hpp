#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <map>
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

void breadth_first_search(unordered_map<int, vector<int>> adjList, int root, unordered_map<int, bool>& visited);

bool breadth_first_search(unordered_map<int, vector<int>> adjList, int root, int target, unordered_map<int, bool>& visited);

// depth_first_search

void depth_first_traverse(const unordered_map<int, vector<int>> adjList, int root, unordered_map<int, bool>& visited);

bool depth_first_search(const unordered_map<int, vector<int>> adjList, int root, int target, unordered_map<int, bool>& visited);

// topological sort

bool topological_sort_dfs(const unordered_map<int, vector<int>> adjList, unordered_map<int, bool>& visited, vector<int>& sorted_list);


bool topsort_dfs_routine(const unordered_map<int, vector<int>> adjList, int root, unordered_map<int, int>& aug_visited, stack<int>& reverse_sorted_list, bool verbose);

// Remove Invalid Parentheses
bool check(string s);

vector<string> removeInvalidParentheses(string s);

#endif