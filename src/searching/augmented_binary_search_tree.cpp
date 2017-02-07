/*


*/
#include "../../include/searching.hpp"


ABST_Node* build_abst(const vector<int> input){

    /*
         in binary search tree

         left-subtree <= root <= right-subtree

    */
    ABST_Node* root = NULL;

    if(input.empty()) return root;

    stack<ABST_Node*> tracker;

    for(auto x: input){
       ABST_Node* cur = root;
       ABST_Node* parent = root;
       bool ifleft = false;
       ABST_Node* node = new ABST_Node(x);
       node->left = NULL;
       node->right = NULL;
       node->size = 0;
       //cout<<node->val<<endl;
       if(root==NULL){
          root = node;
          continue;
       }
       //search for insersion place
       while(cur!=NULL){ //unitl the leaf
          if(x >= cur->val){
             ifleft = false;
             parent = cur;
             tracker.push(parent); //store all parents along the path
             cur = cur->right; //search right subtree if > root
          }
          else{
             ifleft = true; 
             parent = cur; 
             tracker.push(parent); //store all parents along the path
             cur = cur->left;  //search left subtree if < root
          }
       }
       if(ifleft)
          parent->left = node;
          while(!tracker.empty()){
            ABST_Node* cur_parent = tracker.top();
            tracker.pop();
            cur_parent->size = cur_parent->size + 1;
          }
       else
          parent->right = node;
          while(!tracker.empty()){
            ABST_Node* cur_parent = tracker.top();
            tracker.pop();
            cur_parent->size = cur_parent->size + 1;
          }
    }
    return root;
}


void insert_abst(ABST_Node*& root, int val){
    stack<ABST_Node*> tracker;
    ABST_Node* new_node = new ABST_Node(val);
    if(root==NULL){
       root = new_node;
       return;
    }
    bool ifleft = false;
    BST_Node* cur = root;
    BST_Node* parent = root;
    while(cur!=NULL){
       if(val >= cur->val){
           ifleft = false;
           parent = cur;
           tracker.push(parent);
           cur = cur->right;
       }else{
           ifleft = true;
           parent = cur;
           tracker.push(parent);
           cur = cur->left;
       }
    }
    if(ifleft){
       parent->left = new_node;
       while(!tracker.empty()){
           ABST_Node* cur_parent = tracker.top();
           tracker.pop();
           cur_parent->size = cur_parent->size + 1;
       }
    }else{
       parent->right = new_node;
       while(!tracker.empty()){
           ABST_Node* cur_parent = tracker.top();
           tracker.pop();
           cur_parent->size = cur_parent->size + 1;
       }
    }

}