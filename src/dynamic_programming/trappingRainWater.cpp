/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!



To solve this problem, we need to know the [water level] for each cell so that we can use the (water level - ground level (height[i])) to accumulate water

the water level on each cell i is defined by 

   min{local peak on the left of i, local peak on the right of i}

so need two linear scan to find the local peak 


*/

#include <vector>

int trap(vector<int>& height) {
    if(height.empty()) return 0;
    int n = height.size();
    if(n==1) return 0;
    //dynamic programming
    //to find the space that contains water we need 
    //  the left edge: the local peak point on left
    //  the right edge: the local peak point on right
    // use these two values to define the water level and then compute the difference between ground level to water level to add them
    // 
    vector<int> dp(n, 0); //finally will be the water level at given cell
    for(int i=1; i<n; i++){
        //local peak on the left of i
        dp[i] = max(dp[i-1], height[i-1]);
    }
    dp[n-1] = min(dp[n-1], height[n-1]);
    for(int i=n-2; i>=0; i--){
        //combine with local peak on the right of i to form the water level
        int temp = max(dp[i+1], height[i]);
        dp[i] = min(dp[i], temp);
    }
    int res = 0;
    for(int i=1; i<n; i++){
        res += (dp[i] - height[i])>0 ? dp[i] - height[i] : 0;
    }
    return res;
}