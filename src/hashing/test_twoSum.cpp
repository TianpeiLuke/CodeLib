#include "../../include/hashing.hpp"


bool load_vector(string filename, vector<int>& nums){
    nums.clear();
    ifstream infile(filename);
    cout<<"Load data "<<endl;
    while(infile){
        string line;
        if(!getline(infile, line)) break;
        istringstream ss(line);
        int temp;
        ss>>temp;
        nums.push_back(temp);
    }
    if(!infile.eof()){
        cerr<<"Corrupted file!"<<endl;
        return false;
    }
    cout<<"size of data "<<nums.size()<<endl;
    return true;
}



int main(int argc, char* argv[]){
    int upper = 10000;
    if(argc<4){
       upper = 10000; 
    }else
       upper = stoi(argv[3], NULL, 10);

    int lower = -10000;
    if(argc < 3){
       lower = -10000;
    }else
       lower = stoi(argv[2], NULL, 10);

    if(lower > upper){
       cerr<<"Error: the lower is greater than upper bound."<<endl;
       return -1;
    }

    string filename;
    if(argc < 2){
       filename = "../../data/2sum.txt";
    }else
       filename = argv[1];

    vector<int> nums;
    if(!load_vector(filename, nums)){
        return -1;
    }
    int iter = 0;
    int count = 0 ;
    float progress = 0.0;
    int barWidth = 50;
    vector<int> result;
    for(int target=lower; target<=upper; target++){
        iter ++;
        //================================================================
        progress = float(iter) / float(upper-lower + 1); 
        cout<<"[";
        int pos = barWidth * progress;
        for(int ii=0; ii< barWidth; ++ii){
            if( ii < pos ) cout<< "=";
            else if (ii == pos) cout<<">";
            else cout<< " ";
        }
        cout<<"] "<< int(progress * 100.0) << " % "<<" Loop "<<iter<<"\r";
        cout.flush();
        //================================================================
        result = twoSum(nums, target);
        if(result.empty()){ 
           count ++;
           //cout<<endl<<"valid target ratio: "<<count<<"/"<<(upper-lower+1)<<"\r";
           //cout.flush();
        }
        else result.clear();
    }
    cout<<endl<<"valid target ratio: "<<count<<"/"<<(upper-lower+1)<<endl;
    return 0;
}


