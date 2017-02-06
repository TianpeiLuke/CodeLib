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


// kthLargestElem_heap using min-heap and max-heap

bool kthLargestElem_heap(vector<int> input, int& median, int k,  vector<int>&history);

bool kthLargestElem_heap(string filename, int& median, int k,  vector<int>&history, int length);



// median maintenance for a stream of data

bool medMaintanence(string filename, int length, vector<int>& history);


#endif
