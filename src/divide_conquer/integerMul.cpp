#include "../../include/divide_conquer.hpp"


vector<int> IntegerMul(vector<int> a,  vector<int> b ){
     // Implement Integer multiplication using  Karatsuba algorithm
     // with divide-and-conquer scheme. `
     // x[0] is the Leftmost digit, x[n-1] is the Rightmost digit
     bool ifprint = false;
     int n = a.size();
     int m = b.size();
     vector<int> result;
     if(n==1 && m==1){
        result.clear();
        if(a[0]*b[0] >= 10){
          result.push_back(a[0]*b[0]/10);
        }
        result.push_back((a[0]*b[0]) % 10);
        return result;
     }
     if(IsZeroVec(a) || IsZeroVec(b)){
        result.clear();
        result.push_back(0);
        return result;
     }

     // select 2^n precision 
     int maxN = 1<<int(ceil(log2(double(max(n,m)))));
     vector<int> x(maxN, 0);
     vector<int> y(maxN, 0);
     copy(a.begin(), a.end(), x.end()-n);
     copy(b.begin(), b.end(), y.end()-m);
     if (ifprint){
        cout<<"x"<<endl;
        Print(x);
        cout<<"y"<<endl;
        Print(y);
     }
     // Use Divide-and-Conquer algorithm
     // 
     // x = 10^(n/2)*a + b
     // y = 10^(n/2)*c + d
     // x*y= 10^n (a*c) + 10^(n/2) (a*d+ b*c) +b*d
     // a*d + b*c = (a+b)*(c+d) - a*c- b*d
     vector<int>::const_iterator UfirstX = x.begin();
     vector<int>::const_iterator UlastX = x.begin() + x.size()/2;
     vector<int>::const_iterator LfirstX = x.begin()+ x.size()/2;
     vector<int>::const_iterator LlastX = x.end();
     vector<int> Upperx(UfirstX, UlastX); //a
     vector<int> Lowerx(LfirstX, LlastX); //b
     vector<int>::const_iterator UfirstY = y.begin();
     vector<int>::const_iterator UlastY = y.begin() + y.size()/2;
     vector<int>::const_iterator LfirstY = y.begin()+ y.size()/2;
     vector<int>::const_iterator LlastY = y.end();
     vector<int> Uppery(UfirstY, UlastY); //c
     vector<int> Lowery(LfirstY, LlastY); //d

     // a*c
     vector<int> UxUy = IntegerMul(Upperx, Uppery);
     if(ifprint){
        cout<<"a*c"<<endl;
        Print(UxUy);
     }

     // b*d
     vector<int> LxLy = IntegerMul(Lowerx, Lowery);
     if(ifprint){
        cout<<"b*d"<<endl;
        Print(LxLy);
     }
     // (a+b)*(c+d)
     vector<int> tempUxLx = IntegerAdd(Upperx, Lowerx);
     vector<int> tempUyLy = IntegerAdd(Uppery, Lowery);
     if(ifprint){
         cout<<"a+b"<<endl;
         Print(tempUxLx);
         cout<<"c+d"<<endl;
         Print(tempUyLy);
     }
     vector<int> UxLxUyLy = IntegerMul(tempUxLx, tempUyLy);
     if(ifprint){
         cout<<"(a+b)*(c+d)"<<endl;
         Print(UxLxUyLy);
     }
     // a*d + c*b = (a+b)*(c+d) - a*c - b*d
     vector<int> temp5 = IntegerAdd(UxUy, LxLy);
     vector<int> UxLyAddUyLx = IntegerSub(UxLxUyLy, temp5);

     // 10^n*(a*c) + 10^(n/2)*(a*d + c*b) + b*d
     vector<int> temp1(2*maxN, 0);
     copy(LxLy.begin(), LxLy.end(), temp1.end()- LxLy.size());
     vector<int> temp2(2*maxN, 0);
     copy(UxUy.begin(), UxUy.end(), temp2.end()- UxUy.size()-maxN);
     vector<int> temp3(2*maxN, 0);
     copy(UxLyAddUyLx.begin(), UxLyAddUyLx.end(), temp3.end()- maxN/2-UxLyAddUyLx.size());
     vector<int> temp4 = IntegerAdd(temp1, temp2); 
     vector<int> temp = IntegerAdd(temp3, temp4);
     result.assign(temp.begin(), temp.end());
     if (ifprint){
        cout<<"===  Result "<<endl;
        Print(result);
        cout<<"====="<<endl;
     }
     return result;
}



int main(int argc,  char* argv[]){

    string filename;
    bool test;

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
      vector<int> true_res_mul;
      vector<bool> correct_mul;
      cout<<"Test multiplication"<<endl;
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
          true_res_mul.clear();
          String2Int(record[2], true_res_mul);
          ReduceZerosLeft(true_res_mul); 
          String2Int(record[0], x);
          String2Int(record[1], y);
          bool isequal;
          vector<int> res_mul = IntegerMul(x,y);
          ReduceZerosLeft(res_mul);
          isequal = (res_mul == true_res_mul);
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
      
      cout<<"Test multiplication"<<endl;
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
