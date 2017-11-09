#include <iostream>
#include <string>
using namespace std;

bool sub_check(string k){
    int length = k.length()-1;
    for(int tmp = length; tmp>0; tmp=tmp-2){
        if(k[tmp]!='*'){
            return false;
        }
    }
    return true;
}

void del(string & s, string & k){
    //
    int length= s.length()-1;
    for(int tmp = length; tmp >=0; tmp--){
        if(s[tmp]==s[tmp-1]){
            s.erase(s.length()-1);
        }
    }
    length = k.length()-1;
    for(int tmp = length; tmp >=0; tmp--){
        if(k[tmp]==k[tmp-1]){
            k.erase(s.length()-1);
        }
    }
    return;
}

bool check(string s, string k, bool dot, bool star){
    int ls = s.length();
    int lk = k.length();
    if(ls==0&&lk==0){
        return true;
    }else if(ls==0&&lk!=0){
        return sub_check(k);
    }else if(ls!=0&&lk==0){
        if(dot&&star){
            return true;
        }
        return false;
    }
    ls--;lk--;
    
    if(k[lk]==s[ls]){
        if(!star){
            k.erase(k.length()-1);
            s.erase(s.length()-1);
            return check(s,k,false,false);
        }else{
            //process del all same in s and k
            del(s,k);
            return check(s,k,false,false);
        }
    }
    
    if(k[lk]=='*'){
        k.erase(k.length()-1);
        return check(s,k,false,true);
    }
    
    if(k[lk]=='.'){
        if(!star){
            k.erase(k.length()-1);
            s.erase(s.length()-1);
            return check(s,k,false,false);
        }else{
            if(ls==0||lk==0){
                k.erase(k.length()-1);
                return check(s,k,true,true);
            }
            k.erase(k.length()-1);
            for(int tmp = lk-1; tmp>=0; tmp--){
                if(k[tmp]==s[ls]){
                    if(check(s,k,true,true)){
                        return true;
                    }
                }
                k.erase(k.length()-1);
            }
            return false;
        }
    }
    
    if(star){
        k.erase(k.length()-1);
        s.erase(s.length()-1);
        return check(s,k,false,false);
    }
    //s not equal k
    //k is not * or . (((so they are different)
    return false;
}

int main(){
    cout << sub_check("a*b*c*d*")<<endl;
    
    cout << check("aa","a",false,false) <<endl;
    cout << check("aa","aa",false,false) <<endl;
    cout << check("a","a*",false,false) <<endl;
    cout << check("aa",".*",false,false) <<endl;
    cout << check("ab",".*",false,false) <<endl;
    cout << check("aab","c*a*b",false,false) <<endl;
    
    return 0;
}
