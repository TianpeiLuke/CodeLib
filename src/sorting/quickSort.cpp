#include "../../include/sorting/quickSort.hpp"

int indexMedian(vector<int>& sequence, int i, int j){
/*
   The median-of-three:
       first find the first, middle, final elem; for even number of 2k, use kth elem as median
       find the median of the above three numbers use it as the pivot
       
*/
    int len = j-i+1;
    if (len==0 || len==1) return i;
    int mid = i;
    if(len % 2 == 0){
       mid = i+len/2-1;
    }
    else{
       mid = i+ int((len+1)/2) - 1;
    }
    int x1 = sequence[i];
    int x2 = sequence[mid];
    int x3 = sequence[j];
    int max_12 = max(x1, x2);
    int max_23 = max(x2, x3);
    if(max_12 <= x3){
       return (x2>=x1 ? mid: i); // x1< x2 < x3
    }
    else if(max_23 <= x1){ // x3< x2 < x1
       return (x2>= x3 ? mid: j);
    }
    else{   //x3 < x2
       return (x3 >= x1? j: i);
    }
}


int indexPivot(vector<int> sequence, int i, int j, int pivot_choice){
   if(pivot_choice == 0){
       // return first elem
       return i; 
   }
   else if (pivot_choice == 1){
       // return last elem
       return j; 
   }
   else{
       // return median-of-three
       return indexMedian(sequence, i,j);
   }
}


int QuickSortCountSub(vector<int>& sequence, int i, int j, int pivot_choice = 0){
/*
    QuickSort on sequence within the range [i,j] 
    pivot_choice:
                 = 0; first elem
                 = 1; last elem
                 = 2; median-of-three choice
*/
    if (i>= j) return 0;

    // index of Pivot point
    int idxPivot = indexPivot(sequence, i, j, pivot_choice); 
    // switch pivot to first element
    int Pivot = sequence[idxPivot];
    swap(sequence[i], sequence[idxPivot]); 
    /*
           suppose the sequence is sorted within [i+1, idxRightLarge], where 
           sequence[i+1 : idxLeftLarge-1] < sequence[i]
           sequence[idxLeftLarge, idxRightLarge] >= sequence[i]
    */
    // for all elem <= idxLeftLarge-1, sequence[elem] < sequence[idxPivot]
    int idxLeftLarge = i+1;  
    // for all elem > idxRightLarge, no order given
    int idxRightLarge = i+1; 
    int numCompare = j-i;     
   
    for(idxRightLarge=i+1; idxRightLarge <= j; idxRightLarge++){
        if (sequence[idxRightLarge] < Pivot){
           swap(sequence[idxRightLarge], sequence[idxLeftLarge]);
           idxLeftLarge ++ ;
        }
    }
    int final_pos = i;
    if (idxLeftLarge > j){ 
       // all elem < sequence[i]
       swap(sequence[i], sequence[j]);
       final_pos = j;
       numCompare = numCompare + QuickSortCountSub(sequence, i, j-1, pivot_choice);
    }
    else if(idxLeftLarge == i+1){ 
       // all elem >= sequence[i]
       final_pos = i;
       numCompare = numCompare + QuickSortCountSub(sequence, i+1, j, pivot_choice);
    }
    else{
       final_pos = idxLeftLarge - 1;
       swap(sequence[final_pos], sequence[i]);
       numCompare = numCompare + QuickSortCountSub(sequence, i, final_pos-1, pivot_choice);
       numCompare = numCompare + QuickSortCountSub(sequence, final_pos+1, j, pivot_choice);
    }

    return numCompare;
}

int QuickSortCount(vector<int>& sequence, int n, int pivot_choice){
/*
          Quick Sort algorithm on sequence
  Output:
        the number of comparisons 
*/
    int i=0; int j= n-1;
    return QuickSortCountSub(sequence, i, j, pivot_choice);
}

void read_data(string filename, vector<int>& sequence, int& n){
    ifstream myfile (filename);
    sequence.clear();
    n = 0;
    string line;
    if (myfile.is_open()){
       while ( getline (myfile,line) ){
          sequence.push_back(stoi(line));
          n ++;
       }
       myfile.close();
    }
    else cout << "Unable to open file"; 
}





int main(){
   
   vector<int> sequence;
   int n = 0;
   string filename = "../../data/dataSort.txt";
   cout<<"Read data from "<<filename<<endl;
   read_data(filename, sequence, n);
   /* for(auto i=sequence.begin(); i<sequence.end(); i++){
       cout << *i << '\n';
       
   }*/
   vector<int> sequence_1(n,0);
   vector<int> sequence_2(n,0);
   vector<int> sequence_3(n,0);

   cout<<"Total size "<< n<< endl;
   cout<<"Count comparison ... "<<endl;
   cout<<"First elem as pivot:"<<endl;
   int pivot_choice = 0;
   copy(sequence.begin(), sequence.end(), sequence_1.begin());
   int numCompare = QuickSortCount(sequence_1, n, pivot_choice);
   cout<<"Total comparison: "<<numCompare<<endl;
   cout<<"Last elem as pivot:"<<endl;
   pivot_choice = 1;
   copy(sequence.begin(), sequence.end(), sequence_2.begin());
   numCompare = QuickSortCount(sequence_2, n, pivot_choice);
   cout<<"Total comparison: "<<numCompare<<endl;
   cout<<"Median-of-three elem as pivot:"<<endl;
   pivot_choice = 2;
   copy(sequence.begin(), sequence.end(), sequence_3.begin());
   numCompare = QuickSortCount(sequence_3, n, pivot_choice);
   cout<<"Total comparison: "<<numCompare<<endl;
   
   for(auto i=sequence_1.begin(); i<sequence_1.end(); i++){
       cout << *i << '\n';
       
   }
   return 0;
}