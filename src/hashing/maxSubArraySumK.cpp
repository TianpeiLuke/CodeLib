/*
Maximum length of Subarray that Sums to K 

Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?

*/

#include "../../include/hashing.hpp"

int maxSubArrayLen(vector<int>& nums, int k) {
    // A two-sum problem in accumulation 
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return (nums[0] == k); //if only one see if it is k;
    
    vector<int> sumAt(n, 0);
    int i;
    //sumAt[0] = nums[0];
    //for(i=1; i<n; i++){
    //    sumAt[i] = sumAt[i-1] + nums[i];
    //}
    // Note that sum[i:j] = sumAt[j] - sumAt[i-1]; so we need to find two sumAt[i] and sumAt[j] so that their difference is k
    unordered_map<int, int> hash;
    hash[0] = -1; //important to avoid storing sumAt[i] = 0
    
    int max_len = 0;
    for (i=0; i<n; i++){
        if(i ==0) sumAt[0] = nums[0];
        else{
            sumAt[i] = sumAt[i-1] + nums[i];
        }
        // if not seen, insert in hash table
        if(hash.find(sumAt[i]) == hash.end()){
            hash[sumAt[i]] = i;
        }
        if( hash.find(sumAt[i] - k) != hash.end() && hash[sumAt[i] - k] != i){
            max_len = max(max_len,  i-  hash[sumAt[i] - k]);
        }
    }
    return max_len;
}






