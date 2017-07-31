/*

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.


The key to solve this problem is explore the maximal rectangle above each row i (0->n)

for each row scan, keep track of the left vertical edge and right vertical edge as well as the maximal continuous 1s above row i

the area of rectangle will be the (right edge - left edge)*height
 
*/


int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return 0;
    int n = matrix.size(), m = matrix[0].size();

    vector<int> height(m, 0);  //maximal height of continuous 1s
    vector<int> left(m,0);     //left vertical edge
    vector<int> right(m,m);  //right vertical edge
    int res=0;
    
    for(int i=0; i<n; i++){
        int curleft = 0, curright = m; //control the left and right vertical edge loc 
        for(int j=0; j<m; j++){
            if(matrix[i][j] == '1') height[j] ++;
            else height[j] = 0; //if == '0', restart 
        }
        for(int j=0; j<m; j++){
            if(matrix[i][j] == '1') left[j] = max(left[j], curleft);
            else if(matrix[i][j] == '0'){
                curleft = j+1;//if is '0', left edge move right
                left[j] = 0;
            } 
        }
        
        for(int j=m-1; j>=0 ; j--){
            if(matrix[i][j] == '1') right[j] = min(right[j], curright);
            else if(matrix[i][j] == '0'){ 
                curright = j;//if is '0', right edge move left
                right[j] = m;
            } 
        }
        
        for(int j=0; j<m; j++){
            res = max(res, (right[j] - left[j])*height[j]); //find a single rectangle with maximal area
        }
        
    }
    return res;
    
}