/*

    compute the kth Largest Element in a stream via priority_queue 

    using a max-heap and a min-heap

    max_heap = x_1 <= x_2 < .. <= x_k

    min_heap = x_(n-k+1) <= x_(n-k+1) <= .. x_n
*/


#include "../../include/searching.hpp"

bool kthLargestElem_heap(string filename, int& result, int k,  vector<int>&history, int length=10){
    string line;
    ifstream inputFile (filename); 
    if(!inputFile.is_open()){
       cout<<"Unable to read file !"<<endl;
       return false;
    }

    if(!history.empty()) history.clear();
    int count  = 0;
    // using two heaps to retrieve the median of the stream
    /*
         the max_heap store all val < current key

         the min_heap store all val >= current key
    */
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap; 

    int max_small = 0;
    int min_large = 0;
    while(getline(inputFile, line)){
        //each line contains one single number
        count ++;
        if(count > length) break;
        int cur_key = stoi(line, nullptr, 10);
        if(count<=k){
           // by definition, the kth largest elem only make sense for data size > k
           min_heap.push(cur_key);
        }else{
           min_large = min_heap.top();
           if(cur_key >= min_large){
               min_heap.push(cur_key);
           }
           else{
               max_heap.push(cur_key);
           }
        
        /* by definition, the size of min_heap == k 
         */
           int length_min_heap = min_heap.size();
           int length_max_heap = max_heap.size();
           int num_pop = 0;
          // cout<<length_max_heap<<" "<<length_min_heap<<endl;
           if(length_min_heap > k){
             //reduce min_heap 
               num_pop = length_min_heap - k;
               while(num_pop>0){
                   num_pop -- ;
                   int temp = min_heap.top();
                   min_heap.pop();
                   max_heap.push(temp);
               }
           }else if(length_min_heap < k){
              //reduce max_heap
               num_pop = k - length_min_heap;
               while(num_pop>0){
                   num_pop --;
                   int temp = max_heap.top();
                   max_heap.pop();
                   min_heap.push(temp);
               }
           }
        //length_min_heap = min_heap.size();
        //length_max_heap = max_heap.size();
        //cout<<length_max_heap<<" "<<length_min_heap<<endl;
        // compute the median 
           if(count >= k){
               result = min_heap.top();
               history.push_back(result);
               cout<<"No."<<count<<" "<<k<<"-th largest "<<result<<endl;
           }
        }
    }
    inputFile.close();
    if(count < length || count< k) cout<<"Not enough size !"<<endl;
    return true;
}




bool kthLargestElem_heap(vector<int> input, int& result, int k,  vector<int>&history){

    if(!history.empty()) history.clear();
    int count  = 0;
    // using two heaps to retrieve the median of the stream
    /*
         the max_heap store all val < current key

         the min_heap store all val >= current key
    */
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap; 

    int max_small = 0;
    int min_large = 0;
    for(auto cur_key : input){
        //each line contains one single number
        count ++;
        if(count<=k){
           // by definition, the kth largest elem only make sense for data size > k
           min_heap.push(cur_key);
        }else{
           min_large = min_heap.top();
           if(cur_key >= min_large){
               min_heap.push(cur_key);
           }
           else{
               max_heap.push(cur_key);
           }
        
        /* by definition, the size of min_heap == k 
         */
           int length_min_heap = min_heap.size();
           int length_max_heap = max_heap.size();
           int num_pop = 0;
           // cout<<length_max_heap<<" "<<length_min_heap<<endl;
           if(length_min_heap > k){
              //reduce min_heap 
               num_pop = length_min_heap - k;
               while(num_pop>0){
                   num_pop -- ;
                   int temp = min_heap.top();
                   min_heap.pop();
                   max_heap.push(temp);
               }
            }else if(length_min_heap < k){
               //reduce max_heap
               num_pop = k - length_min_heap;
               while(num_pop>0){
                   num_pop --;
                   int temp = max_heap.top();
                   max_heap.pop();
                   min_heap.push(temp);
               }
            }
           //length_min_heap = min_heap.size();
           //length_max_heap = max_heap.size();
           //cout<<length_max_heap<<" "<<length_min_heap<<endl;
           // compute the median 
           if(count >= k){
              result = min_heap.top();
              history.push_back(result);
              cout<<"No."<<count<<" "<<k<<"-th largest "<<result<<endl;
           }
        }
    }
    if(count< k){
        cout<<"Not enough size !"<<endl;
        return false;
    }
    return true;
}


//int main(int argc, char* argv[]){
//   int length = 0;
//   if(argc < 4){
//      length = 10000;
//   }else{
//      length = stoi(argv[3], nullptr, 10);
//   }
//
//   int k = 1;
//   if(argc < 3){
//       k = 5;
//   }else{
//       k = stoi(argv[2], nullptr, 10);
//   }
//
//   string filename;
//   vector<int> input;
//   if(argc < 2){
//       input = {1, 10, 99, 5, 4, 6, 9, 24, 80, 11, 15};
//      //filename = "../../data/Median.txt";
//   }else{
//      filename = argv[1];
//   }
//
//   int result = 0;
//    
//   vector<int> history;
//
//   if(argc >=2 ){
//       if(!kthLargestElem_heap(filename, result, k, history, length)){
//          return -1;
//       }
//   }
//   else{
//       if(!kthLargestElem_heap(input, result, k, history)){
//          return -1;
//       }
//   }
//
//   cout<<"final result: "<<k<<"-th Largest elem in size of "<<length<<": "<<result<<endl;
//   return 0;
//}

