#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool check_repeat(vector<string> list, string sym){
    for(int tmp =0; tmp < list.size(); tmp++){
        if(list[tmp]==sym){
            return false;
        }
    }
    return true;
}

void StoreDiscard(vector<string> & list, string& bag){
    ostringstream ss;
    for(int tmp =0; tmp< list.size(); tmp++){
        ss << list[tmp];
    }
    bag = ss.str();
    list.clear();
}

int main()
{
    string l;
    getline(cin,l);
    cout << l << endl;
    
    vector<string> list;
    string record;
    int length=0;
    int loest;
    
    string tmps;
    
    for(int tmp=0; tmp < l.length(); tmp++){
        ostringstream ss;
        ss << l[tmp];
        tmps = ss.str();
        //tmps=l[tmp].c_str();
        if(check_repeat(list,tmps)){
            list.push_back({l[tmp]});
            length ++;
        }else{
            if(list.size() > loest){
                StoreDiscard(list,record);
                loest = length;
                length = 0;
            }else{
                list.clear();
                length =0;
            }
        }
    }
    
    cout << record <<endl;
    
    /*
    vector <string> t;
    t.push_back("1");
    t.push_back("2");
    t.push_back("3");
    t.push_back("4");
    string tt;
    StoreDiscard(t,tt);
    cout<< tt << endl;
    */
    
    
   cout << "Hello World" << endl; 
   
   return 0;
}
