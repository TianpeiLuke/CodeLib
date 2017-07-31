#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdlib>

using namespace std;

void func(vector<int>& v,  int& epsilon){
    //in this function implement transform for each elem of vector v

    transform(v.begin(), v.end(), v.begin(), 
                [epsilon](int x)->int{ 
                    if(x < epsilon) 
                       return 0; 
                    else 
                       return (x-epsilon); 
                  }
              );
}

void print(vector<int> v){

    for_each(v.begin(), v.end(), 
        [](int x){
             cout<<x<<" ";
        });
    cout<<endl;
}


void zip(vector<int> keys, vector<int> vals, vector<pair<int, int>>& hash ){

    //take two arrays and output an array of pairs

    //in python zip(key, val) = ((key1, val1), (key2, val2), ...)

    transform(keys.begin(), keys.end(), vals.begin(), hash.begin(), 
            [](int key, int val)->pair<int,int>{
                 return make_pair(key, val);
            }
    );

}


void printPair(vector<pair<int, int>> v){

    for_each(v.begin(), v.end(), 
        [](pair<int, int> x){
             cout<<x.first<<"->"<<x.second<<endl;
        });
}


int main(){

   int n = 10;
   vector<int> x(n, 10);
   for(auto& s: x){
      s = rand() % 30 + 1985;
   }

   vector<int> val(n, 1);
   vector<pair<int, int>> hash(n, make_pair(0,0));

   int epsilon = 2000;
   func(x, epsilon);

   print(x);

   zip(x, val, hash);
   printPair(hash);

   return 0;
}