/*
   Compute edit distance using the dynamic programming

   [Definition]: 
     strings a and b on an alphabet Σ (e.g. the set of ASCII characters, the set of bytes [0..255], etc.), the edit distance d(a, b) is the minimum-weight series of edit operations that transforms a into b. One of the simplest sets of edit operations is that defined by Levenshtein in 1966:[2]

     a)  Insertion of a single symbol. If a = uv, then inserting the symbol x produces uxv. This can also be denoted ε→x, using ε to denote the empty string.
     b)  Deletion of a single symbol changes uxv to uv (x→ε).
     c)  Substitution of a single symbol x for a symbol y ≠ x changes uxv to uyv (x→y).

[Observation 1]
     The last character in the string must either be matched/substituted, inserted or deleted. Chopping off the characters involved in the last operation leave a pair of smaller strings.     

===============================================================================
Let i, j be the last character of the relevent prefix of P and T. Let D[i,j] be the minimal number of operations between sub-string P1, P2, .., Pi and sub-string Tj

-------------------------------------
D[i,j] = min{
----------------------------------------
    1)  D[i-1, j-1] or D[i-1, j-1]+1, for (Tj = Pi), 

i.e. either match or substitute i-th character of P and j-th character of T. Depending on whether the tail of P and T is the same. If P[i] = T[j], then D[i,j] = D[i-1, j-1] by insertion; if P[i] \= T[j], then by substitution at P[i], D[i,j] = D[i-1,j-1] + 1

-------------------------------------------------
    2)  D[i-1, j] + 1,  for (Tj \= Pi), and  need one more in P, Tj <- P(i-1) + insertion a new character at P[i]

--------------------------------------------------
    3)  D[i, j-1] + 1,  for (Tj \= Pi), and  have an extra in P, Tj<-  P(i)  + deletion a character at tail P[i]

    }

===============================================================================
   Using dynamic programming with a two-dimensional table to store distinct pair (i,j)  

Initialization:
    D[0,j] = size(Tj)
    D[i,0] = size(Pi)


    ==================================================================
     j 
    -----------------------------------------------------------------
  i  0                right(deletion)                         2  3  4  5  ...
    ---------------------------------------------------------------- 
     down(insertion)  down-right(insertion or substitution)

   
*/

#include "../../include/dynamic_programming.hpp"


int edit_distance(const string pattern, const string text){
   
   if(text=="") return pattern.size();
   if(pattern=="") return text.size();
   int p_n = pattern.size();
   int t_n = pattern.size();


   vector<vector<int>> dynamic_table; // size p_n x t_n
   //initialization
   for(int i=0; i<p_n+1; i++){
      vector<int> row(t_n+1, 0); 
      if(i==0){
         for(int j=0; j<t_n+1; j++){
             row[j] = j;
         }
      }
      else{
         row[0] = i;
      }
      dynamic_table.push_back(row);
   }
   //loop over the two-dimenisional table
   for(int i=1; i<p_n+1; i++){
      for(int j=1; j< t_n+1; j++){
         if(text[j-1] == pattern[i-1])
            dynamic_table[i][j] = dynamic_table[i-1][j-1]; 
         else{
            dynamic_table[i][j] = min(min(dynamic_table[i-1][j-1]+1, dynamic_table[i-1][j]+1), dynamic_table[i][j-1] + 1 );
         }
      }
   }

   return dynamic_table[p_n][t_n]; 
}