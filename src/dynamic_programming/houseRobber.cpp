/*

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.


Note that for two neighboring house, you can only choose one to rob, resulting two situations

maxRob[i] := maximal money robbed from nums[0:i]
         = max(maxRob[i-1], maxRob[i-2]+nums[i])

*/

#include <vector>

int rob(vector<int>& nums) {
    if(nums.empty()) return 0;
    int n = nums.size();
    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);
    vector<int> maxRob(n, 0); //the maximal money to rob for nums[0:i]
    maxRob[0] = nums[0];
    maxRob[1] = max(nums[0], nums[1]);
    for(int i=2; i<n; i++){
        maxRob[i] = max(maxRob[i-2]+nums[i], maxRob[i-1]); //either rob its neighbor or not but to rob it 
    }
    return maxRob[n-1];
}