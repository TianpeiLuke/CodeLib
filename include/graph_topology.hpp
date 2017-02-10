#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
#include <fstream>
#include <sstream>
#include <utility>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <climits>

#ifndef _GRAPH_TOPOLOGY
#define _GRAPH_TOPOLOGY

#ifndef _NAMESPACE
#define _NAMESPACE
using namespace std;
#endif

//karger randomized MinCut 
int unique_pair(const map<pair<int, int>, bool> edge_visit);

int edgeChange(const unordered_map<int, int> node_groups, map<pair<int, int>, bool>& edge_visit);

void nodeMerge(const pair<int, int> edge, unordered_map<int, int>& node_groups);

pair<int, int> edgeRandPick(map<pair<int, int>, bool>& edge_visit);

int total_groups(const unordered_map<int, int> node_groups);

int computeRandCuts(vector<pair<int, int>>& edgeList);

int kargerMinCut(const vector<pair<int, int>> edgeList, int max_loop=1000);


// strong connected components in directed graph
bool any_nonvisited(const unordered_map<int, bool> visited, int& root);

vector<pair<int,int>> SCC(unordered_map<int, vector<int>> adjList, unordered_map<int, bool> visited, bool verbose);

void dfs_first_SCC(const unordered_map<int, vector<int>> adjList, int root, unordered_map<int, bool>& visited, unordered_map<int, int>& finishing_time, unordered_map<int, int>&leader, bool verbose);

void dfs_second_SCC(const unordered_map<int, vector<int>> adjList, const int root, unordered_map<int, bool>&visited, vector<pair<int, int>>&SCC, unordered_map<int, int>& leader, bool verbose);


// dijkstra's algorithm
void dijkstra(const unordered_map<int, vector<int>> adjList, const unordered_map<int, vector<int>> weights, unordered_map<int, bool>& visited,  int source, unordered_map<int, int>& min_path);

void dijkstra_routine(const unordered_map<int, vector<int>> adjList, const unordered_map<int, vector<int>> weights,  unordered_map<int, bool>& visited, vector<pair<int,int>>& nodeHeap, unordered_map<int, int>& min_path);

// union find and number of island

void unionNode(vector<int>& Parent, int p, int q);

int find(vector<int>& Parent, int q);

bool boundCheck(vector<vector<char>>& grid, int idx, int idy, int n, int m);

int numIslands(vector<vector<char>>& grid);

#endif
