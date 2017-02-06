/*
Binary Tree Vertical Order Traversal

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:

Given binary tree [3,9,20,null,null,15,7],
   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,8,4,0,1,7],
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]
Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5),
     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2
return its vertical order traversal as:
[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]

* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

#include "../../include/hashing.hpp"

vector<vector<int>> verticalOrder(TreeNode* root) {
/*
 The vertical order is a breadth-first traverse 

 for each node, store the TreeNode, and store the loc of node 
 for each left-child, its loc is loc of its root -1; 
 for each right-child, its loc is the loc of its root + 1



*/
    vector<vector<int>> result;
    // use the breadth-first search 
    if (root == NULL) return result;

    unordered_map<int, vector<int>> hash_nodes;
    queue<pair<int, TreeNode*>> level_queue;

    level_queue.push(make_pair(0, root));

    int left_most_key = 0;  //record the begining of the key in true order
    int right_most_key = 0; //record the end of the key in true order

    while(!level_queue.empty()){
        pair<int, TreeNode*> fnode = level_queue.front();
        int loc = fnode.first;
        TreeNode* cur = fnode.second;
        
        left_most_key = min(left_most_key, loc);
        right_most_key = max(right_most_key, loc);

        hash_nodes[loc].push_back(cur->val);

        level_queue.pop();
        if(cur->left){
            // left child has loc -1
            level_queue.push(make_pair(loc-1, cur->left));
        }
        if(cur->right){
            // right child has loc + 1
            level_queue.push(make_pair(loc+1, cur->right));
        }
    }
    for(int key_i=left_most_key; key_i<= right_most_key; key_i++){
        result.push_back(hash_nodes[key_i]);
    }

    return result;

}


