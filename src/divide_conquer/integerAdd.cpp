#include "../../include/divide_conquer.hpp"

void Print(vector<int> x){
  // Print 
  for(auto i=x.begin(); i!= x.end(); i++){
     cout<<*i;
  }
  cout<<endl;
}

vector<int> IntegerAdd(vector<int> x,  vector<int> y){
     // Integer addition 
     // x[0] is the Leftmost digit, x[n-1] is the Rightmost digit
     int n = x.size();
     int m = y.size();
     int j = n-1;
     int k = m-1;
     int carry = 0;
     vector<int> result( max(n,m) + 1, 0);
     // add from right to left
     for (auto i = result.rbegin(); i != result.rend(); i++){
        if (j>=0 && k>=0){
           *i = (x[j] + y[k] + carry) % 10;
           carry = (x[j] + y[k] + carry) / 10;
           j--;
           k--;
           //cout<<"Print"<<endl;
           //cout<<*i<<endl;
         }
        else if(j<0 && k>= 0){
           *i = (y[k]+ carry) % 10;
           carry = (y[k] + carry) / 10;
           k--;
           //cout<<*i<<endl;
        }
        else if(k<0 && j>= 0){
           *i = (x[j] + carry) % 10;
           carry = (x[j] + carry) / 10;
           j--;
           //cout<<*i<<endl;
        }
        else if(k<0 && j<0 && carry > 0){
           *i = carry;
           carry = 0;
           //cout<<*i<<endl;
        }
     }

     // Return digits with leftmost being nonzero
     ReduceZerosLeft(result); 
     return result;
}

vector<int> IntegerSub(vector<int> x,  vector<int> y){
     // Integer substraction 
     // assume that x > y
     // x[0] is the Leftmost digit, x[n-1] is the Rightmost digit
     int n = x.size();
     int m = y.size();
     int j = n-1;
     int k = m-1;
     int carry = 0;
     vector<int> result( max(n,m), 0);

     for (auto i = result.rbegin(); i != result.rend(); i++){
        if (j>=0 && k>=0){
           *i = (x[j]- y[k] + carry) >= 0 ? (x[j] - y[k] + carry) : (x[j]- y[k] + 10+ carry) % 10 ;
           carry = (x[j] - y[k]+ carry) >= 0 ? 0 : -1;
           j--;
           k--;
         }
        else if(k<0 && j>= 0){
           *i = (x[j]+ carry) >=0 ? (x[j] + carry) : (x[j]+10 + carry) % 10 ;
           carry = (x[j] + carry) >= 0 ? 0: -1;
           j--;
        }
     
     }
     ReduceZerosLeft(result); 
     return result;
}


bool IsZeroVec(const vector<int> x){
     bool res = false;
     for(auto i = x.begin(); i<x.end(); i++){
         if(*i != 0) return res;
     }
     res = true;
     return res;
}


void ReduceZerosLeft(vector<int>& x){
     // Delete zeros in the leftmost digits
     if(x.empty()) return;
     auto i = x.begin();
     while(*i == 0 && x.size() > 1){
         x.erase(i);
         i = x.begin();
     }
     if(x.empty()) x.push_back(0);
}


bool IsNonZero (int i) {
  return (i!=0);
}

void String2Int(string str_x, vector<int>& x){
     if (!x.empty()) x.clear();
     if (str_x == "") return;
     for(int i=0; i<str_x.length(); i++)
        x.push_back(int(str_x.at(i) - '0'));
}

void ZeroPad(vector<int>& x){
     int n = x.size();
     int pow2n = 1<<int(ceil(log2(double(n))));
     if(n!= pow2n){
        int k = pow2n - n;
        for(int i=0;i<k;i++)
           x.insert(x.begin(), 0);
     }
}


/* 
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
       vector<int> x1;
       x1 = {0,9,9,9,9,9,9,9};
       vector<int> y1;
       y1 = {0,0,0,0,0,0,0,1};
       vector<int> TrueResult;
       TrueResult = {1,0,0,0,0,0,0,0};
       vector<int> result = IntegerAdd(x1,y1);
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
      vector<bool> correct; 
      vector<int> true_res_add;
      vector<bool> correct_add;
      vector<int> true_res_sub;
      vector<bool> correct_sub;
      if(choice == 0){
          cout<<"Test addition"<<endl;
      }else if(choice == 1){
          cout<<"Test substraction"<<endl;
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
          }
          if(isequal){  //equal(res_add.begin(), res_add.end(), true_res_add.begin())){
               cout<< "success" <<endl;
               if(choice ==0)
                  correct_add.push_back(true);
               else if (choice == 1)
                  correct_sub.push_back(true);

           }
           else{ 
               cout<< "fail"<<endl;
               if(choice ==0)
                   correct_add.push_back(false);
               else if (choice == 1)
                   correct_sub.push_back(false);
           }
          //data.push_back(record) ;
          k ++; 
         
      }
      if(!infile.eof()) cerr<<"Corrupted file!\n";
      
      if(choice == 0){
          cout<<"Test addition"<<endl;
          cout<<"Correct/Total:"<<count(correct_add.begin(), correct_add.end(), true)<<"/"<<k<<endl;
          if(k!= count(correct_add.begin(), correct_add.end(), true)) cout<<"Fail"<<endl;
          else cout<<"Success!"<<endl;
          for(int idx=0; idx< correct_add.size(); idx++ ){
              if(!correct_add[idx])
                 cout<<"Incorrect idx: "<<idx<<endl;
          }
      }else if(choice == 1){
          cout<<"Test substraction"<<endl;
          cout<<"Correct/Total:"<<count(correct_sub.begin(), correct_sub.end(), true)<<"/"<<k<<endl;
          if(k!= count(correct_sub.begin(), correct_sub.end(), true)) cout<<"Fail"<<endl;
          else cout<<"Success!"<<endl;
          for(int idx=0; idx< correct_sub.size(); idx++ ){
              if(!correct_sub[idx])
                 cout<<"Incorrect idx: "<<idx<<endl;
          }
      }
     
   }
   return 0;
}
*/
