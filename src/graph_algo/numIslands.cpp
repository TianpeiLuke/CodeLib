/*
    Number of Islands

   Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

   Example 1:

   11110
   11010
   11000
   00000
   Answer: 1

   Example 2:

   11000
   11000
   00100
   00011
   Answer: 3


*/
#include "../../include/graph_topology.hpp"

int numIslands(vector<vector<char>>& grid) {
    /*
          Use the Union find method 
          

    */
    int dir[2][2] = {{1,0}, {0,1}};  // only goes down and goes right

    if(grid.empty() || grid.size() == 0 ) return 0;
    int n = grid.size();
    int m = grid[0].size();
    // for each grid on the map, find the parent of the grid
    //    that is reachable 
    vector<int> Parent(m*n);
    int result = 0;
    int i=0; int j=0;

    // initialization; each point has own root 
    for(i=0; i< n; i++){
        for(j=0; j<m; j++){
            int id = i*m+j;
            Parent[id] = id; 
        }
    }
    
    //If merging occurs, then result --
    for(i=0; i< n; i++){
        for(j=0; j<m; j++){
            if(grid[i][j] == '0'){
                continue;
            }
            for(auto& direction: dir){
                int pi = i+ direction[0];
                int qj = j+ direction[1];
                if(boundCheck(grid, pi, qj, n, m) ){
                    int id = i*m+j;
                    int idNeighbor = pi*m + qj;
                    // merge the root if they beong to the same union
                    unionNode(Parent, id, idNeighbor);
                }
            }
        }
    }

    for(i=0; i< n; i++){
        for(j=0; j<m; j++){
            int id = i*m+j;
            if(grid[i][j] == '1' && Parent[id] == id){
                result++; // count the number of roots
            }
        }
    }
    return result;
}



bool boundCheck(vector<vector<char>>& grid, int idx, int idy, int n, int m){
    return (idx >=0 && idx < n  && idy >=0 && idy < m && grid[idx][idy] == '1');
}


int find(vector<int>& Parent, int q){
     /*
        find the root of the tree that the pointer q belongs to
    */
    int cur = q;
    while(Parent[cur] != cur){
        cur = Parent[cur];
    }
    return cur;
}



void unionNode(vector<int>& Parent, int p, int q){
    /*
        if the root for the pointer p and pointer q is the same, we should
            merge the root of one of the tree record
    */
    int rp = find(Parent, p);
    int rq = find(Parent, q);
    if(rp == rq) return;
    Parent[rp] = rq;
}