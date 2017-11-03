#include <iostream>
#include <vector>
#include <string>
using namespace std;

int checkp(vector<string> sample){
    ;
}


void loop(string & line, int& maxlen, vector<string>& out){
    if(!line.empty()){
        vector<string> sample;
        int record;
           for(int tmp = line.length(); tmp >0; tmp--){
                sample.push_back({line[tmp-1]});
                if((record=checkp(sample))!=0){
                    if(record >maxlen){
                        ;//sample out;
                    }
                }
            }
            line.erase(line.length()-1);
            sample.clear();
            loop(line,maxlen,out);
            return;
    }else{
        return;
    }
}


int main(){
    cout<<"life is lonly";
    return 0;
}
