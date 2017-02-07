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
       node->size = 1;
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
       if(ifleft){
          parent->left = node;
          while(!tracker.empty()){
            ABST_Node* cur_parent = tracker.top();
            tracker.pop();
            cur_parent->size = cur_parent->size + 1;
          }
       }
       else{
          parent->right = node;
          while(!tracker.empty()){
            ABST_Node* cur_parent = tracker.top();
            tracker.pop();
            cur_parent->size = cur_parent->size + 1;
          }
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
    ABST_Node* cur = root;
    ABST_Node* parent = root;
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

void in_order_traversal_vec(ABST_Node* root){

   if(root == NULL) return;

   stack<ABST_Node*> tracker;
   tracker.push(root);
   unordered_map<ABST_Node*, bool> visit;
   visit[NULL] = false;
   // backtracking, begining from the left-subtree
   while(!tracker.empty()){
      ABST_Node* cur = tracker.top();
      //by construction, cur not NULL
      try{
         bool trial = visit.at(cur);
      }catch(const out_of_range& oor){
         visit[cur] = false;
      }
      //*========= key is to judge when to visit ===============
      if(cur->left == NULL || visit[cur->left]==true){ //
        //visit if left subtree is empty
        cout<<"node value: "<<cur->val<<" size "<<cur->size<<endl;
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