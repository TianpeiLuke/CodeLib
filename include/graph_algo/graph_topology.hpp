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


void SCC(vector<vector<int>> adjList, unordered_map<int, int> nodeloc, vector<int>& SCC_size, int verbose);




#endif
