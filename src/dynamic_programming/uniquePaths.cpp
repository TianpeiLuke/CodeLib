/*
 robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Since the robot can only go down and go right, we can determine the number of unique paths for first row and first columns, for the rest, 

res[i][j] = res[i-1][j] + res[i][j-1]

*/

#include <vector>

int uniquePaths(int m, int n) {
    if(m==0 && n==0) return 0;
    if(m==1 || n==1) return 1;
    vector<vector<int>> res;
    for(int i=0; i<m; i++){
        vector<int> row(n, 0);
        res.push_back(row);
    }
    for(int i=0; i<m; i++) res[i][0] = 1;
    for(int j=0; j<n; j++) res[0][j] = 1;
    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            res[i][j] = res[i-1][j] + res[i][j-1];
        }
    }
    
    return res[m-1][n-1];
}