


#include "../../include/searching.hpp"




void in_order_traversal_recur(BST_Node* root){

   /*
          simply implementation of in-order traversal via recursion

          in-order [left sub-tree, root, right sub-tree]
   */

    if (root == NULL) return;
    BST_Node* cur = root;
    while(cur!=NULL){
        in_order_traversal_recur(cur->left);
        cout<<"node value: "<<cur->val<<endl;
        in_order_traversal_recur(cur->right);
    }
}


void in_order_traversal_vec(BST_Node* root){
   /*
       implement the in-order traversal via backtracking using stack
   */
   if(root == NULL) return;
 
   stack<BST_Node*> tracker;
   tracker.push(root);

   // backtracking, begining from the left-subtree
   while(!tracker.empty()){
      BST_Node* cur = tracker.top();
      //by construction, cur not NULL

      //*========= key is to judge when to visit ===============
      if(cur->left == NULL){ //
        //visit if left subtree is empty
        cout<<"node value: "<<cur->val<<endl;
        tracker.pop();
        //then beginning traverse the right subtree
        if(cur->right != NULL) tracker.push(cur->right);
      }else{
        tracker.push(cur->left); //by default, traverse througth the left subtree
      }

   }

}
