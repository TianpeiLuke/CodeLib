#include "../../include/searching.hpp"


int main(int argc, char* argv[]){

    unordered_map<char, vector<char>> LookUpTable;
   
    LookUpTable['1'] = {'a', 'b', 'c','d'};
    LookUpTable['2'] = {'e', 'f'};
    LookUpTable['3'] = {'g', 'h'};
    LookUpTable['4'] = {'i', 'j', 'k', 'l'};
    LookUpTable['5'] = {'m', 'n'};
    LookUpTable['6'] = {'o', 'p', 'q'};
    LookUpTable['7'] = {'r', 's', 't'};
    LookUpTable['8'] = {'u', 'v', 'w'};
    LookUpTable['9'] = {'x', 'y', 'z'};
    LookUpTable['0'] = {' ', '-'};

    string input;
    if(argc < 2){
        input = "11552";
    }
    else
        input = argv[1];

    vector<string> results;
    results = backtracking_dfs(input, LookUpTable);
    cout<<"All possible decoding results: "<<endl;
    for(auto result: results){
        cout<<result<<" ";
    }cout<<endl;
}
