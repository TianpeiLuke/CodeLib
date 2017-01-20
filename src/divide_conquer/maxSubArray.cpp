/*
Problem statement:

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using thedivide and conquer approach, which is more subtle.

*/
#include "../../include/divide_conquer.hpp"



int maxSubArray_v1(vector<int>& nums){
/*
    using divide-and-conquer with O(n*log(n)) time complexity
    return the largest sum of contiguous subarray
*/
   int n = nums.size();
   return maxSubArrayAuxiliary(nums, 0, n-1);
}



int maxSubArrayAuxiliary(vector<int>& nums, int startIdx, int endIdx){
/*
    Helper function in maxSubArray_v1, called recursively 
    divide the array in two halves [startIdx, midIdx-1] and [midIdx+1, endIdx]
    there are three possible cases
       1) the target subarray does not contain midIdx, lies in the first half
       2) the target subarray does not contain midIdx, lies in the second half
       3) the target subarray contains the midIdx

*/
   if(startIdx >= endIdx) return 0;
   int midIdx = (startIdx+endIdx)/2; 
   
   int result = 0;
   int maxLeft = maxSubArrayAuxiliary(nums, startIdx, midIdx-1);
   int maxRight = maxSubArrayAuxiliary(nums, midIdx+1, endIdx);
   int i = midIdx - 1;
   int accMaxLeft = 0; int accMaxRight = 0;
   int tempLeft = 0; int tempRight = 0;
   for(;i>= startIdx; i--){
      tempLeft = tempLeft + nums[i];
      if(tempLeft > accMaxLeft) accMaxLeft = tempLeft;
   }
   i = midIdx + 1;
   for(; i<= endIdx; i++){
      tempRight = tempRight + nums[i];
      if(tempRight > accMaxRight) accMaxRight = tempRight;
   }
   result = accMaxLeft + accMaxRight + nums[midIdx];
   return max(max(maxLeft, maxRight), result);
}


int main(){
   vector<int> nums;
   nums = {-2,1,-3,4,-1,2,1,-5,4};
   cout<<"Input Array"<<endl;
   for(auto i=nums.begin(); i<nums.end(); i++){
      cout<<*i<<" ";
   } cout<<endl;
   cout<<"The largest sum of all contiguous subarray (divide-and-conquer)"<<endl;
   int result = maxSubArray_v1(nums);
   cout<<result<<endl;
   cout<<"The largest sum of all contiguous subarray (dynamic programming)"<<endl;
   int result2 = maxSubArray_v2(nums);
   cout<<result2<<endl;
}