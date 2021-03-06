

#include "../../include/searching.hpp"


BST_Node* build_bst(const vector<int> input){
    /*
         in binary search tree

         left-subtree <= root <= right-subtree

    */
    BST_Node* root = NULL;

    if(input.empty()) return root;
 
    for(auto x: input){
       BST_Node* cur = root;
       BST_Node* parent = root;
       bool ifleft = false;
       BST_Node* node = new BST_Node(x);
       node->left = NULL;
       node->right = NULL;
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
             cur = cur->right; //search right subtree if > root
          }
          else{
             ifleft = true; 
             parent = cur; 
             cur = cur->left;  //search left subtree if < root
          }
       }
       if(ifleft)
          parent->left = node;
       else
          parent->right = node;
    }
    return root;
}

void insert_bst(BST_Node*& root, int val){
    BST_Node* new_node = new BST_Node(val);
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
           cur = cur->right;
       }else{
           ifleft = true;
           parent = cur;
           cur = cur->left;
       }
    }
    if(ifleft){
       parent->left = new_node;
    }else{
       parent->right = new_node;
    }
}


