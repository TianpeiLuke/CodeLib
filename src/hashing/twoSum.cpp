/*
  Given an array of integers, return indices of the two numbers such that they add up to a specific target.

  You may assume that each input would have exactly one solution.

  Example:
  Given nums = [2, 7, 11, 15], target = 9,

  Because nums[0] + nums[1] = 2 + 7 = 9,
  return [0, 1].

 UPDATE (2016/2/13):
 The return format had been changed to zero-based indices. Please read the above updated description carefully.

*/

#include "../../include/hashing.hpp"


vector<int> twoSum(vector<int>& nums, int target){
   /*
      using the hash table as inverse mapping, it will track position j = hash[target-num[i]] 
      This is O(n) complexity compare to the naive O(n^2) complexity
   */
    vector<int> result;
    if(nums.empty()) return result;
    int n = nums.size();
    if(n<2) return result;
    
    unordered_map<int, int> hash;
    for(int i=0; i<n; i++){
        int temp = nums[i];
        hash[temp] = i;
    }
    
    for(int i=0; i<n; i++){
        int temp = nums[i];
        int j = 0;
        try {
              j = hash.at(target-temp); 
        }
        catch (const std::out_of_range& oor) {
              continue;
        }
        // if the target - nums[i] exists
        if(j!= i){
            result.push_back((i<j)? i: j);
            result.push_back((i<j)? j: i);
        }
        return result;
    }
    return result;
}




