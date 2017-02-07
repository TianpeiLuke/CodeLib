#include "../../include/dynamic_programming.hpp"


int main(int argc, char* argv[]){
   vector<string> input_strings;
   string filename; 
   if(argc<2){
      //input_strings   = {"her", "they"};//{"thou shalt not", "you should not"};//
      input_strings   = {"kitten", "kitchen", "familiar", "similarity"};
   }else{
      ifstream input_file(filename);
      if(!input_file.is_open()){
          cout<<"cannot open file"<<endl;
          return -1;
      }
      string line;
      while(getline(input_file, line)){
         input_strings.push_back(line);
      }
      input_file.close();
   }

   for(int i=0; i<input_strings.size(); i=i+2){
       int edist = edit_distance(input_strings[i], input_strings[i+1]);
       cout<<"Edit distance btw ( "<<input_strings[i]<<" , "<<input_strings[i+1]<<" )= "<<edist<<endl;
   }

}
