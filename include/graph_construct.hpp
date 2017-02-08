#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <utility>
#include <cmath>

#ifndef _GRAPH_CONSTRUCT
#define _GRAPH_CONSTRUCT

#ifndef _NAMESPACE
#define _NAMESPACE
using namespace std;
#endif

void copy_AdjList(const vector<vector<int>*> AdjList, const vector<int> NodeList, vector<vector<int>*>& Copy_AdjList, vector<int>& Copy_NodeList);

void show_AdjList(vector< vector<int>* >& AdjList, int & n);

void read_AdjList(string filename, vector< vector<int>* >& AdjList, vector<int>& NodeList, int & n);

void clean_AdjList(vector< vector<int>* >& AdjList, int& n);

bool Graph_load_edge(string filename, vector<vector<int>>& adjList, unordered_map<int, int>& nodeloc);

void Graph_reverse(const vector<vector<int>> adjList, const unordered_map<int, int> nodeloc,  vector<vector<int>>& adjList_reverse);


bool Graph_load_adjList(string filename, vector<vector<int>>& adjList);




#endif
