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

//====================================================================
// define an adjacency list graph representation implemented using hash table

bool Graph_load_edges(string filename, unordered_map<int, vector<int>>& adjList, unordered_map<int, bool>& visited);

bool Graph_load(string filename, unordered_map<int, vector<int>>& adjList, unordered_map<int, bool>& node_visit);

bool Graph_load_weights(string filename, unordered_map<int, vector<int>>& adjList, unordered_map<int, vector<int>>& weights, unordered_map<int, bool>& node_visit);


void Graph_reverse(const unordered_map<int, vector<int>> adjList, unordered_map<int, vector<int>>& adjList_reverse);

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

//======================================================================
// define the  disjoint-set data structure

void init_unionFind(const unordered_map<int, vector<int>> adjList, unordered_map<int,int>& parent);

int find(unordered_map<int,int>& parent, int node);


void unionNode(unordered_map<int, int>& parent, int p, int q);



#endif
