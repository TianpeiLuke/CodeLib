#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>


#ifndef _HASHING
#define _HASHING

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};



// two Sum
vector<int> twoSum(vector<int>& nums, int target);

// maxSubArray Sum to k
int maxSubArrayLen(vector<int>& nums, int k);

// binary Tree Vertical Order Traverse 
vector<vector<int>> verticalOrder(TreeNode* root);

#endif