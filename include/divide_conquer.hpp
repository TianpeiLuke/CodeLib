#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <sstream>
#include <random>

#ifndef _DIVIDE_CONQUER
#define _DIVIDE_CONQUER
using namespace std;

// For integerSum and integerMul
void Print(vector<int> x);
void ZeroPad(vector<int>& x);
bool IsZeroVec(const vector<int> x);
bool IsNonZero(int i);
void String2Int(string str_x, vector<int>& x);
void ReduceZerosLeft(vector<int>& x);

vector<int> IntegerAdd ( vector<int> x , vector<int> y );
vector<int> IntegerSub ( vector<int> x , vector<int> y );
vector<int> IntegerMul ( vector<int> x , vector<int> y ); // using Karatsuba algorithm 

// For maxSubArray
int maxSubArray_v1(vector<int>& nums);
int maxSubArray_v2(vector<int>& nums);
int maxSubArrayAuxiliary(vector<int>& nums, int startIdx, int endIdx);

// For kthLargestElem
int pivot_sel(int beginIdx, int endIdx, int choice);
int twoWayPartition(vector<int>& nums, int beginIdx, int endIdx, int pivotIdx);
int threeWayPartition(vector<int>& nums, int beginIdx, int endIdx, int pivotIdx);
int kthLargestElem(vector<int>& nums, int k);
int kthLargestElemAux(vector<int>& nums, int beginIdx, int endIdx, int k);

// For search2DMat
bool searchMatrix(vector<vector<int>>& matrix, int target);
bool searchMatrixAux(vector<vector<int>>& matrix, int target, int ulX, int ulY, int lrX, int lrY);


#endif

