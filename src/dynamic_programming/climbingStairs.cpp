/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
*/

//use the dynamic programming to solve it

#include <vector>

int climbStairs(int n) {
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(n == 2) return 2;
    vector<int> climbs(n+1, 0);
    climbs[0] = 1;
    climbs[1] = 1;
    climbs[2] = 2;
    for(int i=3; i<=n; i++){
        climbs[i] = climbs[i-1] + climbs[i-2];
    }
    return climbs[n];
}