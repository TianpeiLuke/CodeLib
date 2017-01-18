/*
   Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

   For example,
   Given [3,2,1,5,6,4] and k = 2, return 5.

   Note: You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

#include "../../include/divide_conquer.hpp"


int kthLargestElem(vector<int>& nums, int k){
    int n = nums.size();
    if(k>n || k<= 0) cerr << "Error: beginIdx >=0 and endIdx <= nums.size()";
    return kthLargestElemAux(nums, 0, n-1, k);
}

int pivot_sel(int beginIdx, int endIdx, int choice){
    if(choice == 0){ 
       // the first elem
       return beginIdx; 
    }else if (choice == 1){
       // the last elem
       return endIdx;
    }else {
       // choose uniformly from [beginIdx, endIdx]
       unsigned seed = chrono::system_clock::now().time_since_epoch().count();
       default_random_engine eng (seed);
       uniform_int_distribution<int> dist(beginIdx, endIdx);
       int RandIdx = dist(eng);
       //cout<<"Random Index "<<RandIdx+1<<endl;
       return RandIdx;
    }

}


int twoWayPartition(vector<int>& nums, int beginIdx, int endIdx, int pivotIdx){
     /*
        in-place partition the sequence [beginIdx, endIdx] according to the pivotIdx
        return the position of pivot in partial sorted nums
     */
     if(beginIdx == endIdx) return beginIdx;
     swap(nums[beginIdx], nums[pivotIdx]);
     

     int i = beginIdx + 1;
     int j = endIdx;
     // two-way partition
     while(i<=j){
        if(nums[i] > nums[beginIdx]){
           swap(nums[i], nums[j]);
           j--;
        }
        else i++;
     }
     swap(nums[i-1], nums[beginIdx]);
     return i-1;
}

int threeWayPartition(vector<int>& nums, int beginIdx, int endIdx, int pivotIdx){
     /*
          suppose the sequence is sorted within [beginIdx+1, rightLargeIdx]
          where 
                nums[beginIdx+1: leftLargeIdx-1 ] < pivot = nums[beginIdx]
                nums[leftLargeIdx, rightLargeIdx] >= pivot
          
          for all <= leftLargeIdx-1, 

     */
     if(beginIdx == endIdx) return beginIdx;
     swap(nums[beginIdx], nums[pivotIdx]);
     
     int leftLargeIdx = beginIdx + 1;
     int rightLargeIdx = beginIdx + 1;
     for(; rightLargeIdx <= endIdx; rightLargeIdx ++){
           if(nums[rightLargeIdx] < nums[beginIdx]){
                swap(nums[rightLargeIdx], nums[leftLargeIdx]);
                leftLargeIdx ++ ;
           }

      }
      int finalIdx = beginIdx;
      if (leftLargeIdx > endIdx){
          // all elems < pivot
          swap(nums[beginIdx], nums[endIdx]);
          finalIdx = endIdx;
      }else if(leftLargeIdx == beginIdx + 1){
          // all elem >= pivot
          finalIdx = beginIdx;
      }else{
          finalIdx = leftLargeIdx - 1;
          swap(nums[beginIdx], nums[finalIdx]);
      }
      return finalIdx;
}




int kthLargestElemAux(vector<int>& nums, int beginIdx, int endIdx, int k){
    /*
       Similar to quicksort, choose a pivot x and 
       have a partial partition so that all data before x smaller than x (Less_Half) and all data after x is larger than x (Greater_Half). 
       Then
       1) if x is the kth largest element then we are done.
       2) For x is s-th largest element, where s<k, we call the function for sequence in Greater_Half with k <- (k-s) 
       3) For s > k, call function in Less_Half, with k unchanged
    */
     if(beginIdx<0 || endIdx > nums.size()-1) cerr << "Error: beginIdx >=0 and endIdx <= nums.size()";
     if(beginIdx > endIdx) cerr<<"Error";
     // cout<<"Find "<<k + beginIdx<<" k "<<k<<" BeginIdx: "<<beginIdx<<endl;
     int choice = 2;
     int pivotIdx = pivot_sel(beginIdx, endIdx, choice);
     // two-way partition
     // int new_pivotIdx = twoWayPartition(nums, beginIdx, endIdx, pivotIdx);
     int new_pivotIdx = threeWayPartition(nums, beginIdx, endIdx, pivotIdx);
 
 //     cout<<"New Pivot Index "<<new_pivotIdx + 1<<endl;
 //     for(auto i = nums.begin(); i< nums.end(); i++)
 //         cout<<*i<<" ";
 //     cout<<endl;
     int global_pivot = new_pivotIdx + 1;
     int global_k = k + beginIdx; 
     if(global_pivot == global_k){
          return nums[new_pivotIdx];
     }else if (global_pivot > global_k ){
          return kthLargestElemAux(nums, beginIdx, new_pivotIdx-1, k);
     }else{
          return kthLargestElemAux(nums, new_pivotIdx+1, endIdx, global_k-global_pivot);
     }
     

}



int main(){
    vector<int> nums;
    nums = {3, 2, 1, 5, 6, 4};
    cout<<"Input Array"<<endl;
    for(auto i = nums.begin(); i< nums.end(); i++)
        cout<<*i<<" ";
    cout<<endl;

    int k = 3;
    int kthElem = kthLargestElem(nums, k);
    cout<<"Input Array (After partial ordering)"<<endl;
    for(auto i = nums.begin(); i< nums.end(); i++)
        cout<<*i<<" ";
    cout<<endl;
    cout<<"The "<<k<<"-th largest element is "<<kthElem<<endl;
}




