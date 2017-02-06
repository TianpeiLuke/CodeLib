


#include "../../include/searching.hpp"




void post_order_traversal_recur(BST_Node* root){

   /*
          simply implementation of in-order traversal via recursion

          post-order [left sub-tree, right sub-tree, root]
   */

    if (root == NULL) return;
    BST_Node* cur = root;
    while(cur!=NULL){
        in_order_traversal_recur(cur->left);
        in_order_traversal_recur(cur->right);
        cout<<"node value: "<<cur->val<<endl;
    }
}


void post_order_traversal_vec(BST_Node* root){
   /*
       implement the post_order traversal via backtracking the left and right sub-tree
   */
   if(root == NULL) return;
 
   stack<BST_Node*> tracker; //store all left-subtree and right-subtree
   tracker.push(root);

   // backtracking, 
   while(!tracker.empty()){
      BST_Node* cur = tracker.top();
      //by construction, cur not NULL

     //*=========== key is to judge when to visit ===============================
      if(cur->left == NULL && cur->right == NULL){
        //visit the node only if both the left subtree and the right subtree are empty
         cout<<"node value: "<<cur->val<<endl;
         tracker.pop();
      }else if(cur->left!=NULL){
         // left subtree non-empty, then traverse the left-subtree
         tracker.push(cur->left); 
      }else{
         // left subtree empty but right subtree non-empty, traverse the right subtree
         tracker.push(cur->right);
      }

   }

}

