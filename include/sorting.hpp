#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <fstream>
#include <utility>


#ifndef _QuickSort
#define _QuickSort

#ifndef _NAMESPACE
#define _NAMESPACE
using namespace std;
#endif


//declaration
int indexMedian(vector<int>& sequence, int i, int j);

int indexPivot(vector<int> sequence, int i, int j, int pivot_choice);

int QuickSortCountSub(vector<int>& sequence, int i, int j, int pivot_choice); 

int QuickSortCount(vector<int>& sequence, int n, int pivot_choice);
 
void read_data(string filename, vector<int>& sequence, int& n);
#endif