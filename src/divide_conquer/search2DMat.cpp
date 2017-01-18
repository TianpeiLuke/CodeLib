/*
   Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

   1) Integers in each row are sorted in ascending from left to right.
   2) Integers in each column are sorted in ascending from top to bottom.

For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

*/

#include "../../include/divide_conquer.hpp"

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty()) return false;
    int m = matrix.size();
    vector<int> row = matrix[0];
    int n = row.size();
    if(m==1 && n==1) return (matrix[0][0] == target);
    return searchMatrixAux(matrix, target, 0, 0, m-1, n-1);
}



bool searchMatrixAux(vector<vector<int>>& matrix, int target, int ulX, int ulY, int lrX, int lrY){
/*
   x -> row no. y-> column no.
   since the matrix is partially ordered in each row and each column, we can divide the matrix is four blocks
   use the midPt = (midX, midY) (0,0) for upper-left corner
         ulMat := upper-left block  (0 <= y <= midY, 0 <= x <= midX) known < midPt
         urMat := upper-right block (midY <= y <= endY, 0 <= x <= midX-1)   unknown to midPt, but tends to be smaller
         llMat := lower-left block; (0 <= y <= midY, midX+1 <= x <= endX)   unknown to midPt, but tends to be larger
         lrMat := lower-right block (midY <= y <= endY, midX <= x <= endX) known > midPt

   each time search for 3/4 given a comparison btw target and matrix[midPt]
       

*/
    if (ulX == lrX and ulY == lrY) return (matrix[ulX][ulY] == target); 
    if (ulX > lrX || ulY > lrY) return false;
    cout<<"UL( "<<ulX<<" , "<<ulY<<" )"<<" and LR( "<<lrX<<" , "<<lrY<<" )"<<endl;
    int midX = (ulX + lrX) / 2;
    int midY = (ulY + lrY) / 2; 
 
    if(matrix[midX][midY] == target) return true;
    else if(matrix[midX][midY] > target){
        // drop the lrMat
       return ( searchMatrixAux(matrix, target, ulX, ulY, lrX, midY-1) || searchMatrixAux(matrix, target, ulX, midY, midX-1, lrY));
    }
    else{
        // drop the ulMat
       return ( searchMatrixAux(matrix, target, ulX, midY+1, lrX, lrY) || searchMatrixAux(matrix, target, midX+1, ulY, lrX, midY));
    }
}


int main(int argc, char* argv[]){
   string filename;
   if(argc < 2)
        filename = "../../data/dataMatrixSearch.txt";
   else
        filename = argv[1];

   vector<vector<int>> matrix;
   vector<int> row;

   ifstream infile( filename );
   cout<<"Load data "<<filename<<endl;
   while(infile){
       string s;
       
       if(!getline(infile, s)) break;
       istringstream ss(s);
       vector<string> record;
        
       row.clear();
       while(ss){
           string sb;
           if (!getline(ss, sb, ',')) break;
           record.push_back(sb);
       }
       string tempStr;
       int tempInt;
       for(int i=0; i<record.size(); i++){
           tempStr = record[i];
           tempInt = stoi(tempStr,nullptr,10);
           row.push_back(tempInt);
       }
       matrix.push_back(row);
   }
   int m1 = matrix.size();
   vector<int> target_row;
   /*for(int i=0; i<m1; i++){
       for(auto j=matrix[i].begin(); j<matrix[i].end(); j++){
        cout<<*j<<" ";
        //target_row.push_back(*i);
   }
   cout<<endl;
   }*/
   for(auto j=matrix[m1-1].begin(); j<matrix[m1-1].end(); j++){
        //cout<<*j<<" ";
        target_row.push_back(*j);
   }
   cout<<endl; 
   matrix.pop_back();
   int target = target_row[0];
   int m = matrix.size();
   int n = matrix[0].size();
   for(int i=0; i< target_row.size(); i++){
       
       cout<<"Find the target "<<target<<" in matrix ( "<<m<<" , "<<n<<" ) ?"<<endl;
       bool ifFind = searchMatrix(matrix, target);
       cout<<(ifFind? "True": "False")<<endl;
       break;
   }

   return 0;
}

