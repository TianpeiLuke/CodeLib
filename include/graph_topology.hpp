#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
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

#ifndef _GRAPH_TOPOLOGY
#define _GRAPH_TOPOLOGY

#ifndef _NAMESPACE
#define _NAMESPACE
using namespace std;
#endif

//karger randomized MinCut 


void EdgePick(vector<int>& NodeList, int& node_i, int& node_j, unsigned seed);

void NodeMerge(vector<vector<int>*>& AdjList, int node_i, int node_j);

int CountCrossingEdges(const vector<vector<int>*> AdjList, const int node_i, const int node_j);

int ComputeCut(vector<vector<int>*> AdjList, vector<int> NodeList, int n);

int kargerMinCut(vector<vector<int>*> AdjList, vector<int> NodeList, int n, int& nLoop);



// strong connected components in directed graph
void SCC(vector<vector<int>> adjList, unordered_map<int, int> nodeloc, vector<int>& SCC_size, int verbose);

void depth_first_SCC(vector<vector<int>> adjList, int root, vector<bool>& visited, vector<int>& finishing_time, vector<int>&leader,  unordered_map<int, int>& nodeIdxMap );


void depth_second_SCC(const vector<vector<int>> adjList, const unordered_map<int, int> nodeIdxMap, const vector<int> finishing_time, vector<int>& leader, vector<int>& SCC_size, vector<bool>& visited);

// union find and number of island

void unionNode(vector<int>& Parent, int p, int q);

int find(vector<int>& Parent, int q);

bool boundCheck(vector<vector<char>>& grid, int idx, int idy, int n, int m);

int numIslands(vector<vector<char>>& grid);

#endif
