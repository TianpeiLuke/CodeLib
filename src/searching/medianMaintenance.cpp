/*
      maintance of the median of a streaming sequence

      use two heaps to store the median value for smaller half data and larger half data

      for each input, with O(log(n)) complexity to insert a heap and O(1) to return the median

      sequentially, takes O(n*log(n)) in total

*/


#include "../../include/searching.hpp"

bool medMaintanence(string filename, int length,  vector<int>& history){
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
        if(max_heap.empty() && min_heap.empty()){
           // the first elem goes to the min_heap
           min_heap.push(cur_key);
        }else{
           min_large = min_heap.top();
           if(cur_key >= min_large){
               min_heap.push(cur_key);
           }
           else{
               max_heap.push(cur_key);
           }
        }
        /* by definition, the size of max_heap <= the size of min_heap <= the size of max_heap + 1
         */
        int length_min_heap = min_heap.size();
        int length_max_heap = max_heap.size();
        int num_pop = 0;
        // cout<<length_max_heap<<" "<<length_min_heap<<endl;
        if(length_min_heap > length_max_heap + 1){
           //reduce min_heap 
            num_pop = length_min_heap - (length_max_heap + 1);
            while(num_pop>0){
                num_pop -- ;
                int temp = min_heap.top();
                min_heap.pop();
                max_heap.push(temp);
            }
         }else if(length_min_heap < length_max_heap){
            //reduce max_heap
            //cout<<"here"<<endl;
            num_pop = length_max_heap - length_min_heap;
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
        int median = 0;
        if(count % 2 == 1){
           median = min_heap.top();
           history.push_back(median);
        }else if(count % 2 == 0){
           median = max_heap.top();
           history.push_back(median);
        }
        cout<<"No."<<count<<" median "<<median<<endl;
        
    }
    inputFile.close();
    if(count < length) cout<<"Not enough size !"<<endl;
    return true;
}


int main(int argc, char* argv[]){
   int length = 0;
   if(argc < 3){
      length = 10000;
   }else{
      length = stoi(argv[2], nullptr, 10);
   }

   string filename;
   if(argc < 2){
      filename = "../../data/Median.txt";
   }else{
      filename = argv[1];
   }
    
   vector<int> history;

   if(!medMaintanence(filename, length,  history)){
       return -1;
   }

   int sum = 0;
   for(auto x: history){
        sum = sum + x;
   }
   sum = sum % 10000;
   cout<<"modulo average of "<<history.size()<<" medians: "<<sum<<endl;
   return 0;
}