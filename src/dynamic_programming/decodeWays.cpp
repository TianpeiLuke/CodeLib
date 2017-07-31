/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26


Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.

*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int numDocodings(string s){
    //similar to climb stairs
    int n = s.size();
    if(n == 0 || s[0] = '0') return 0;
    if(n == 1 || s[0] != '0') return 1;

    vector<int> numWays(n+2, 1); 
    //numWays[i+2] = num of decoding ways for string s[0:i]
    for(int i=2; i<n+2; i++){
        //note thet for size 1 char must be '1' < <'9'
        //for size 2 char, the first digit must not be 0; and must be 1, or 2
        //if size 2 char, the first digit is 2, then the second digit must be <= 6
        int temp = 0;
        if(stoi(s.substr(i-2,1)) >= 1 && stoi(s.substr(i-2,1))<= 9){
           temp += numWays[i-1];
        }
        if(i>=3 && stoi(s.substr(i-3,2)) <= 26 && stoi(s.substr(i-3,1)) > 0 ){
           temp += numWays[i-2];
        }
        if(temp == 0){
            //cannot be decoded
           return 0;
        }
        numWays[i] = temp;
    }
    return numWays[n+1];
}