#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>

#ifndef _GRAPH_CONSTRUCT
#define _GRAPH_CONSTRUCT

#ifndef _NAMESPACE
#define _NAMESPACE
using namespace std;
#endif

bool Graph_load_edge(string filename, vector<vector<int>>& adjList, unordered_map<int, int>& nodeloc);

void Graph_reverse(const vector<vector<int>> adjList, const unordered_map<int, int> nodeloc,  vector<vector<int>>& adjList_reverse);


bool Graph_load_adjList(string filename, vector<vector<int>>& adjList);




#endif
