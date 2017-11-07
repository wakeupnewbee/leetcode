#include <iostream>
#include <vector>
#include <string>
using namespace std;

int checkp(vector<string> sample){
    int head = 0;
    int tail = sample.size()-1;
    for(int tmp = sample.size()/2; tmp >0; tmp --){
        if(sample[head] != sample[tail]){
            return 0;
        }
        head++;
        tail--;
    }
    return sample.size();
}

void copy_vector(vector<string> sample, vector<string> &out){
    for(int tmp =0; tmp<sample.size(); tmp++){
        out.push_back({sample[tmp]});
    }
    return;
}


void loop(string line, int& maxlen, vector<string>& out){
    if(!line.empty()){
        vector<string> sample;
        int record;
           for(int tmp = line.length(); tmp >0; tmp--){
                sample.push_back({line[tmp-1]});
                if((record=checkp(sample))!=0){
                    if(record >maxlen){
                        maxlen = record;
                        //copy new longest sample into longest;
                        out.clear();
                        copy_vector(sample,out);
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
    int y = 10.88;
    cout << y << endl;
    string line;
    getline(cin,line);
    vector<string> longest;
    int num=0;
    loop(line,num,longest);
    
    cout << "longest pal has length of :" << num << endl;
    for(int tmp=0; tmp < longest.size(); tmp++){
        cout << longest[tmp];
    }
    cout<< endl;
    
    cout<<"life is lonly";
    return 0;
}
