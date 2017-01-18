
#include "../../include/divide_conquer/integerOp.hpp"
#include <fstream>
#include <sstream>

int main(int argc,  char* argv[]){

    string filename;
    bool test;
    int choice;
    if(argc<4){
       choice = 2;
    }
    else choice = atoi(argv[3]);

    if(argc < 3){
       test = false;
    }
    else test = bool(atoi(argv[2]));

    if(argc < 2){
       filename = "../../data/testIntegerMul.txt";
    }
    else   filename = argv[1];
    
   
   if (!test){
       vector<int> x1(64);
       x1 = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5,0,2,8,8,4,1,9,7,1,6,9,3,9,9,3,7,5,1,0,5,8,2,0,9,7,4,9,4,4,5,9,2};

       vector<int> y1(64);
       y1 = {2,7,1,8,2,8,1,8,2,8,4,5,9,0,4,5,2,3,5,3,6,0,2,8,7,4,7,1,3,5,2,6,6,2,4,9,7,7,5,7,2,4,7,0,9,3,6,9,9,9,5,9,5,7,4,9,6,6,9,6,7,6,2,7};

       vector<int> TrueResult;
       TrueResult = {8,5,3,9,7,3,4,2,2,2,6,7,3,5,6,7,0,6,5,4,6,3,5,5,0,8,6,9,5,4,6,5,7,4,4,9,5,0,3,4,8,8,8,5,3,5,7,6,5,1,1,4,9,6,1,8,7,9,6,0,1,1,2,7,0,6,7,7,4,3,0,4,4,8,9,3,2,0,4,8,4,8,6,1,7,8,7,5,0,7,2,2,1,6,2,4,9,0,7,3,0,1,3,3,7,4,8,9,5,8,7,1,9,5,2,8,0,6,5,8,2,7,2,3,1,8,4};
       vector<int> result = IntegerMul(x1,y1);
       ReduceZerosLeft(result); 
       Print(result);
   
       cout << "True:"<<endl;
       Print(TrueResult);
       if (equal(result.begin(), result.end(), TrueResult.begin()))
          cout << "success" << endl;
       else
          cout << "fail" << endl;
   }
   else{
      ifstream infile( filename );
      vector<int> x;
      vector<int> y;
      vector<int> true_res_add;
      vector<bool> correct_add;
      vector<int> true_res_sub;
      vector<bool> correct_sub;
      vector<int> true_res_mul;
      vector<bool> correct_mul;
      if(choice == 0){
          cout<<"Test addition"<<endl;
      }else if(choice == 1){
          cout<<"Test substraction"<<endl;
      }else if(choice == 2){
          cout<<"Test multiplication"<<endl;
      }
      int k = 0;
    
      //vector<vector<string>> data;
      while(infile){
          cout<<"test "<<k<<endl;
          string s;
          if(!getline(infile, s)) break;

          istringstream ss(s);
          vector<string> record;

          while(ss){
             string s;
             if (!getline(ss, s, ',')) break;
             record.push_back(s);
          }
          x.clear();
          y.clear();
          if(choice == 0){
              true_res_add.clear();
              String2Int(record[2], true_res_add);
              ReduceZerosLeft(true_res_add); 
          }else if(choice == 1){
              true_res_sub.clear();
              String2Int(record[3], true_res_sub);
              ReduceZerosLeft(true_res_sub); 
          }else if(choice == 2){
              true_res_mul.clear();
              String2Int(record[2], true_res_mul);
              ReduceZerosLeft(true_res_mul); 
          }
          String2Int(record[0], x);
          String2Int(record[1], y);
          bool isequal;
          if(choice == 0){
              vector<int> res_add = IntegerAdd(x,y); 
              ReduceZerosLeft(res_add);
              isequal = (res_add == true_res_add);
          }else if (choice == 1){
              vector<int> res_sub = IntegerSub(x,y); 
              ReduceZerosLeft(res_sub);
              isequal = (res_sub == true_res_sub);
          }else if (choice == 2){
              vector<int> res_mul = IntegerMul(x,y);
              ReduceZerosLeft(res_mul);
              isequal = (res_mul == true_res_mul);
          }
          if(isequal){  //equal(res_add.begin(), res_add.end(), true_res_add.begin())){
               cout<< "success" <<endl;
               correct_mul.push_back(true);
           }
           else{ 
               cout<< "fail"<<endl;
               correct_mul.push_back(false);
           }
          //data.push_back(record) ;
          k ++; 
         
      }
      if(!infile.eof()) cerr<<"Corrupted file!\n";
      
      if(choice == 0){
          cout<<"Test addition"<<endl;
      }else if(choice == 1){
          cout<<"Test substraction"<<endl;
      }else if(choice == 2){
          cout<<"Test multiplication"<<endl;
      }
      cout<<"Correct/Total:"<<count(correct_mul.begin(), correct_mul.end(), true)<<"/"<<k<<endl;
      if(k!= count(correct_mul.begin(), correct_mul.end(), true)) cout<<"Fail"<<endl;
      else cout<<"Success!"<<endl;
      for(int idx=0; idx< correct_mul.size(); idx++ ){
           if(!correct_mul[idx])
              cout<<"Incorrect idx: "<<idx<<endl;
       }
     
   }
   return 0;
}
