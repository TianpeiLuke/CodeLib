


#include "../../include/searching.hpp"




void in_order_traversal_recur(BST_Node* root){

   /*
          simply implementation of in-order traversal via recursion

          in-order [left sub-tree, root, right sub-tree]
   */

    if (root == NULL) return;
    BST_Node* cur = root;
    if (cur!=NULL){
        in_order_traversal_recur(cur->left);
        cout<<"node value: "<<cur->val<<endl;
        in_order_traversal_recur(cur->right);
    }
}


void in_order_traversal_vec(BST_Node* root){
   /*
       implement the in-order traversal via backtracking using stack and a hash table to record if the node is visited
   */
   if(root == NULL) return;

   stack<BST_Node*> tracker;
   tracker.push(root);
   unordered_map<BST_Node*, bool> visit;
   visit[NULL] = false;
   // backtracking, begining from the left-subtree
   while(!tracker.empty()){
      BST_Node* cur = tracker.top();
      //by construction, cur not NULL
      try{
         bool trial = visit.at(cur);
      }catch(const out_of_range& oor){
         visit[cur] = false;
      }
      //*========= key is to judge when to visit ===============
      if(cur->left == NULL || visit[cur->left]==true){ //
        //visit if left subtree is empty
        cout<<"node value: "<<cur->val<<endl;
        tracker.pop();
        visit[cur] = true;
        //then beginning traverse the right subtree
        if(cur->right != NULL) tracker.push(cur->right);
      }else{
        if(visit[cur->left] == false)
            tracker.push(cur->left); //by default, traverse througth the left subtree
      }

   }

}
