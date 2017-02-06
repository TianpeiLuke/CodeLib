


#include "../../include/searching.hpp"




void pre_order_traversal_recur(BST_Node* root){

   /*
          simply implementation of in-order traversal via recursion

          pre-order [root, left sub-tree, right sub-tree]
   */

    if (root == NULL) return;
    BST_Node* cur = root;
    while(cur!=NULL){
        cout<<"node value: "<<cur->val<<endl;
        in_order_traversal_recur(cur->left);
        in_order_traversal_recur(cur->right);
    }
}


void pre_order_traversal_vec(BST_Node* root){
   /*
       implement the pre-order traversal via a queue of left subtree and backtracking the    root of right subtree along the sequential visit. 
   */
   if(root == NULL) return;
 
   //use the queue to keep track of pre-order visit
   queue<BST_Node*> visit_tube;
   visit_tube.push(root);
   stack<BST_Node*> tracker; //use the stack to track the root of right sub-tree after the sequential visit of the root

   while(!visit_tube.empty()){
      //*=============  key is to judge when to visit ====================
      BST_Node* cur = visit_tube.front();
      // first visit the root
      cout<<"node value: "<<cur->val<<endl;
      visit_tube.pop();
      // keep track of the root of the closet right subtree
      if(cur->right != NULL) tracker.push(cur->right);
      if(cur->left != NULL) visit_tube.push(cur->left); //if left subtree nonempty, visit them  
      else{
          // if the left subtree is empty, then traverse the right subtree
          if(!tracker.empty()){
             BST_Node* cur_right = tracker.top();
             tracker.pop();
             visit_tube.push(cur_right); 
          }
      }
   }

}
