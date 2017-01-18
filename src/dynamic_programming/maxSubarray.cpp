/*
Problem statement:

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using thedivide and conquer approach, which is more subtle.

*/
#include "../../include/dynamic_programming.hpp"

int maxSubArray_v2(vector<int>& nums){
/*
    using dynamic programming, with O(n) time complexity and additional O(n) space complexity
*/
   int maxAllSub = nums[0];
   /* define maxSubEndAt[k] to be the sum of  largest subarray that ends at k
      the final result should be maximum of list maxSubEndAt
      
      equivalently, let maxAllSub store the maximum value of maxSubEndAt[0:k]
      and reduce the array maxSubEndAt as a value, i.e. the sum of largest subarray that ends at k
      maxSubEndAt[k] = max(maxSubEndAt[k-1]+nums[k], nums[k])
       i.e. two cases
              1) attach the new point nums[k] (remain contiguous) and the subarray length + 1
              2) reset the new point as start (broken contiguous), the subarray length = 1
   */
   int maxSubEndAt = nums[0];
   for(int i=1; i<nums.size(); i++){
      maxSubEndAt = max(maxSubEndAt + nums[i], nums[i]);
      maxAllSub = max(maxAllSub, maxSubEndAt);
   }
   return maxAllSub;
}


int main(){
   vector<int> nums;
   nums = {-2,1,-3,4,-1,2,1,-5,4};
   cout<<"Input Array"<<endl;
   for(auto i=nums.begin(); i<nums.end(); i++){
      cout<<*i<<" ";
   } cout<<endl;
   cout<<"The largest sum of all contiguous subarray (dynamic programming)"<<endl;
   int result2 = maxSubArray_v2(nums);
   cout<<result2<<endl;
}