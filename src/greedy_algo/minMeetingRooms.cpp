/*
 Meeting Rooms II

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.


*/
#include "../../include/greedy_algo.hpp"

int minMeetingRooms(vector<Interval>& intervals){
   /*
        to maintain the smallest number of accepted intervals, 
      we need to find a set of intervals that overlaps with largest number of the rest of intervals.
   */
    if(intervals.empty()) return 0;

    int n = intervals.size();
    if(n == 1) return 1;

    vector<int> beginList(n);
    vector<int> endList(n);

    for(auto interval: intervals){
        beginList.push_back(interval.start);
        endList.push_back(interval.end);
    }

    //sort the lists of two end points, respectively

    sort(beginList.begin(), beginList.end());
    sort(endList.begin(), endList.end());

    int i =0; int j=0;
    int count =0;       // record the total number of intervals rejected at current accepted list 
    int maxCount = 0;   
    while(i < endList.size() && j< beginList.size()){
        if( beginList[j] < endList[i] ){
            count ++; //increase by 1 overlap, i.e. the number of rejected intervals increase by 1
            //by default, at least one beginList[] < endList[], so count at least one.
            maxCount = max(maxCount, count);
            j++;
        }else{
            //not go back to zero, 
            //you decrease the accepted interval itself, since previous step include a normal interval
            count --; 
            i++;
        }
    }
    return maxCount;
}