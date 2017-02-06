#include "../../include/searching.hpp"




int main(int argc, char* argv[]){
   int option = 1;
   if(argc < 3){
      option = 2;
   }else{
      option = stoi(argv[2], nullptr, 10);
   }
   string filename = "../../bin";
   vector<int> input;
   if(argc < 2){
      input = {10, 5, 15, 4, 6, 50, 35, 2, 20, 39, 45, 90};
   }else{
      filename = argv[1];
      ifstream input_file(filename);
      if(!input_file.is_open()){
         cout<<"Cannot open file"<<endl;
         return -1;
      }
      string line;
      while(getline(input_file, line)){
         input.push_back(stoi(line, nullptr, 10));
      }
   }

   BST_Node* root = NULL;
   root = build_bst(input);
   
   cout<<root->val<<endl;
   if(option == 1){
      cout<<"In-order traverse: Recursive implementation."<<endl;
      in_order_traversal_recur(root);
      cout<<"Backtracking implementation"<<endl;
      in_order_traversal_vec(root);
   }
   else if (option == 2){
      cout<<"Pre-order traverse: Recursive implementation."<<endl;
      pre_order_traversal_recur(root);
      cout<<"Backtracking implementation"<<endl;
      pre_order_traversal_vec(root);
   }
   else if (option == 3){
      cout<<"Post-order traverse: Recursive implementation."<<endl;
      post_order_traversal_recur(root);
      cout<<"Backtracking implementation"<<endl;
      post_order_traversal_vec(root);
   }
   return 0;
}
