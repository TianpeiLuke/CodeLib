/*
   find the k-th order statistic using the augemented binary search tree
 
   in abst, each node store additional int size = number of nodes in subtree rooted at given node

   given root x, 
         search left subtree and right subtree as below

    if size(left) == k-1, then return root->val;
    if size(left) >= k, then recursively compute k-th order statistic in left-subtree
    if size(left) < k-1, then recursively compute (k-size(left)-1)-th order statistics 
*/




#include "../../include/searching.hpp"

bool kthLargestElem_abst(vector<int> input, int& result, int k){

   if(input.empty()) return false;
   if(k> input.size()) return false;
   bool iffind = false;

   ABST_Node* root;
   root = build_abst(input);

   return kthSmallestElem_abst_aux(root, result, input.size()-k-1);
}


bool kthSmallestElem_abst_aux(ABST_Node* root, int& result,  int k){
   // recursive call the kth order statistics in tree rooted at root

   if(root==NULL) return false;

   if(root->left ==NULL && k==1){//no left subtree, then root is the smallest value
      result = root->val;
      return true;
   }else if(root->left == NULL){
      return false;
   }
   ABST_Node* cur = root;
   int left_num = cur->left->size;
   if(left_num == k-1){
      result = cur->val; //find the root
      return true;
   }else if(left_num < k-1){
      //recursive call to right subtree
      return kthSmallestElem_abst_aux(cur->right, result, k-left_num-1);
   }else if(left_num >= k){
      //recursive call to left subtree
      return kthSmallestElem_abst_aux(cur->left, result, k);
   }

}
