/*
The problems consider a set of tasks. Each task is represented by an interval describing the time in which it needs to be executed. For instance, task A might run from 2:00 to 5:00, task B might run from 4:00 to 10:00 and task C might run from 9:00 to 11:00. A subset of intervals is compatible if no two intervals overlap. For example, the subset {A,C} is compatible, as is the subset {B}; but neither {A,B} nor {B,C} are compatible subsets, because the corresponding intervals within each subset overlap.

The interval scheduling maximization problem (ISMP) is to find a largest compatible set - a set of non-overlapping intervals of maximum size. The goal here is to execute as many tasks as possible.

In this problem, we solve the following problem 

Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.

Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.

Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

*/

#include "../../include/greedy_algo.hpp"

int find_first_finishing(const vector<Interval> intervals, const vector<bool> visit){
    int n = intervals.size();
    int idx = n-1; //the last one, which has maximum end time in intervals
    for(int i=0; i<n; i++){
        if(visit[i]) continue;
        if(intervals[i].end < intervals[idx].end){
            idx = i;
        }
    }
    return idx;
}
    
bool ifoverlap(const Interval a, const Interval b){
    return !((a.end <= b.start) || (a.start >= b.end));
}
    
int eraseOverlapIntervals(vector<Interval>& intervals) {
   /*
     Idea: for each iteration, choose one interval in the accepted set then reject all intervals in the accepted set that are overlapping with the given one 

     How to choose the interval ?
     choose the interval in the accepted region that finishes the first 

   */ 
    int n = intervals.size();
    if(n == 0 || n == 1) return 0;
    vector<bool> accept(n, false);
    vector<bool> visit(n, false);
    int count = 0;
    int num_true = 0;
    //sort according to the end time
    sort(intervals.begin(), intervals.end(), [](Interval& x, Interval& y){return x.end < y.end;});
    
    while(num_true < n){
        int chooseIdx = find_first_finishing(intervals, visit);
        accept[chooseIdx] = true; 
        visit[chooseIdx] = true;
        num_true ++;
        for(int j=0; j<n; j++){
            if(visit[j]) continue;
            if(ifoverlap(intervals[chooseIdx], intervals[j])){
                accept[j] = false;
                visit[j] = true;
                count ++ ;
                num_true ++;
            } 
        }
    }
    // delete the rejected intervals in set
    int i = 0;
    int m = accept.size();
    while(i<m){
       if(!accept[i]){
           accept.erase(accept.begin()+i);
           intervals.erase(intervals.begin()+i);
       }else{
           i ++;
       }
       m = accept.size();
    }
    return count;
}








