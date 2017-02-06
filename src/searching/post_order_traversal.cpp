


#include "../../include/searching.hpp"




void post_order_traversal_recur(BST_Node* root){

   /*
          simply implementation of in-order traversal via recursion

          post-order [left sub-tree, right sub-tree, root]
   */

    if (root == NULL) return;
    BST_Node* cur = root;
    post_order_traversal_recur(cur->left);
    post_order_traversal_recur(cur->right);
    cout<<"node value: "<<cur->val<<endl;
}


void post_order_traversal_vec(BST_Node* root){
   /*
       implement the post_order traversal via backtracking the left and right sub-tree
   */
   if(root == NULL) return;
 
   stack<BST_Node*> tracker; //store all left-subtree and right-subtree
   tracker.push(root);
   unordered_map<BST_Node*, bool> visit;
   visit[NULL] = false;
   // backtracking, 
   while(!tracker.empty()){
      BST_Node* cur = tracker.top();
      //by construction, cur not NULL
      try{
         bool temp = visit.at(cur);
      }catch(const out_of_range& oor){
         visit[cur] = false;
      }
     //*=========== key is to judge when to visit ===============================
      if((cur->left == NULL || visit[cur->left]) && (cur->right == NULL || visit[cur->right])){
        //visit the node only if both the left subtree and the right subtree are empty
         cout<<"node value: "<<cur->val<<endl;
         tracker.pop();
         visit[cur] = true;
      }else if(cur->left != NULL && visit[cur->left] == false){
         // left subtree non-empty, then traverse the left-subtree
         tracker.push(cur->left); 
      }else if(cur->right !=NULL ){ 
         // left subtree empty but right subtree non-empty, traverse the right subtree
         if(visit[cur->right]==false) tracker.push(cur->right);
      }

   }

}

