#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <stack>

#ifndef _GREADY_ALGORITHM
#define _GREADY_ALGORITHM

#ifndef _NAMESPACE
#define _NAMESPACE
using namespace std
#endif

struct Interval {
       int start;
       int end;
       Interval() : start(0), end(0) {}
       Interval(int s, int e) : start(s), end(e) {}
 };

// Non-overlapping Intervals
int find_first_finishing(const vector<Interval> intervals, const vector<bool> visit);

bool ifoverlap(const Interval a, const Interval b);

int eraseOverlapIntervals(vector<Interval>& intervals);

// minimal number of Meeting rooms
int minMeetingRooms(vector<Interval>& intervals);

// 

#endif
