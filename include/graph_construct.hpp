#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <map>
#include <utility>

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

//=================================================================
//bool Graph_load_edge(string filename, vector<vector<int>>& adjList, unordered_map<int, int>& nodeloc);
bool Graph_load_edges(string filename, unordered_map<int, vector<int>>& adjList, unordered_map<int, bool>& visited);

void Graph_reverse(const vector<vector<int>> adjList, const unordered_map<int, int> nodeloc,  vector<vector<int>>& adjList_reverse);


//====================================================================
bool Graph_load(string filename, unordered_map<int, vector<int>>& adjList, unordered_map<int, bool>& node_visit);

void Graph_reverse(const unordered_map<int, vector<int>> adjList, unordered_map<int, vector<int>>& adjList_reverse);
//bool Graph_load_adjList(string filename, vector<vector<int>>& adjList);

void show_AdjList(const unordered_map<int, vector<int>> adjList);

void copy_AdjList(const unordered_map<int, vector<int>> adjList, unordered_map<int, vector<int>>& copy_adjList);


void adjList_to_nodeList(const unordered_map<int, vector<int>>adjList, vector<int>& nodeList);

void nodeList_hash(const vector<int> nodeList, unordered_map<int, bool>& node_visit);

void adjList_to_edgeList(const unordered_map<int, vector<int>>adjList, vector<pair<int, int>>& edgeList );

void edgeList_hash(const vector<pair<int, int>> edgeList, map<pair<int,int>, bool>& edge_visit);

void edgeHash_keyList(const map<pair<int, int>, bool> edge_visit, vector<pair<int, int>>& edgeList);

void edgeList_to_nodeList(const vector<pair<int, int>>edgeList, vector<int>& nodeList);

void edgeList_to_nodeHash(const vector<pair<int, int>>edgeList, unordered_map<int, bool>& node_visit);

void show_edgeList(const vector<pair<int, int>> edgeList);
#endif
