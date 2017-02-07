

#include "../../include/searching.hpp"


int main(int argc, char* argv[]){
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

   ABST_Node* root = NULL;
   root = build_abst(input);
   
   cout<<"In-order traverse: "<<endl;
   cout<<"Backtracking implementation"<<endl;
   in_order_traversal_vec(root);
   int result = -100;
   int k = 5;//k-th largest
   if(kthLargestElem_abst(input, result, k)){
      cout<<"Find the "<<input.size()-k-1<<"th order statistics: "<<result<<endl;
   }
   return 0;
}
