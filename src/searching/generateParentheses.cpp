/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;


vector<string> generateParenthesis(int n) {
    vector<string> res;
    if(n == 0){
        res.push_back("");
        return res;
    }
    string oneParen(1, '(');
    generateParenDFS(n, 1, 1, oneParen, res);
    return res;
}

void generateParenDFS(int n, int leftnum, int pairdiff, string& oneParen, vector<string>& res){
    if(leftnum == n && pairdiff == 0){
        res.push_back(oneParen);
        return;
    }
    else{
        string next = "";
        if(leftnum < n && pairdiff>0){
            next.push_back('(');
            next.push_back(')');
        }else if(leftnum == n && pairdiff>0){ //note that when left parentheses is full, only ")" allowed
            next.push_back(')');
        }else if(leftnum < n && pairdiff==0){ //if the right parentheses matches the left one, only new "(" allowed
            next.push_back('(');
        }
        for(auto c : next){
            oneParen.push_back(c);
            if(c=='('){
                generateParenDFS(n, leftnum+1, pairdiff+1, oneParen, res);
            }else{
                generateParenDFS(n, leftnum, pairdiff-1, oneParen, res);
            }
            oneParen.pop_back();
        }
    }
}