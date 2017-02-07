#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <utility>
#include <functional>


#ifndef _SEARCHING
#define _SEARCHING

#ifndef _NAMESPACE
#define _NAMESPACE
using namespace std;
#endif

// binary search tree
struct BST_Node
{
   int val; 
   BST_Node* left;
   BST_Node* right;
   BST_Node(int x=0): val(x), left(NULL), right(NULL){}
};


BST_Node* build_bst(const vector<int> input);

void insert_bst(BST_Node*& root, int val);

//augmented binary search tree
struct ABST_Node
{
   int val;
   int size; // store the size of nodes in the subtree of node   
   ABST_Node* left;
   ABST_Node* right;
   ABST_Node(int x=0): val(x), size(1), left(NULL), right(NULL){}
};

ABST_Node* build_abst(const vector<int> input);

void insert_abst(ABST_Node*& root, int val);

void in_order_traversal_vec(ABST_Node* root);
// pre-order,  in-order, and post-order traversal

void pre_order_traversal_recur(BST_Node* root);

void pre_order_traversal_vec(BST_Node* root);

void in_order_traversal_recur(BST_Node* root);

void in_order_traversal_vec(BST_Node* root);

void post_order_traversal_recur(BST_Node* root);

void post_order_traversal_vec(BST_Node* root);

// kthLargestElem_heap using min-heap and max-heap

bool kthLargestElem_heap(vector<int> input, int& result, int k,  vector<int>&history);

bool kthLargestElem_heap(string filename, int& result, int k,  vector<int>&history, int length);

// kthLargestElem using augmented binary search tree
bool kthLargestElem_abst(vector<int> input, int& result,  int k);

bool kthSmallestElem_abst_aux(ABST_Node* root, int& result, int k);

// median maintenance for a stream of data

bool medMaintanence(string filename, int length, vector<int>& history);


#endif
