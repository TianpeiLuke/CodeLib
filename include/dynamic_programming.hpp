#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <utility>

#ifndef _DYNAMIC_PROGRAMMING
#define _DYNAMIC_PROGRAMMING

#ifndef _NAMESPACE
#define _NAMESPACE
using namespace std;
#endif

// edit distance

int edit_distance(const string pattern, const string text);


// minimum path sum
int minPathSum(vector<vector<int>>& grid);

// maximum subarray 
int maxSubArray_v2(vector<int>& nums);


#endif
