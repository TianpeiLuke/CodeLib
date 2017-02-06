#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <climits>

#ifndef _GRAPH_TOPOLOGY
#define _GRAPH_TOPOLOGY

#ifndef _NAMESPACE
#define _NAMESPACE
using namespace std;
#endif

// strong connected components in directed graph
void SCC(vector<vector<int>> adjList, unordered_map<int, int> nodeloc, vector<int>& SCC_size, int verbose);

// union find and number of island

void unionNode(vector<int>& Parent, int p, int q);

int find(vector<int>& Parent, int q);

bool boundCheck(vector<vector<char>>& grid, int idx, int idy, int n, int m);

int numIslands(vector<vector<char>>& grid);

#endif
