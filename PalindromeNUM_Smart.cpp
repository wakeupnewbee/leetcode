#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    
    int input = 1234554321;
    int copy = input;
    int tmp;
    int back;
    while(input !=0){
        tmp = input %10;
        back = back*10+tmp;
        input = input/10;
    }
    if(copy == back){
        cout << "it is pal :D"<<endl;
    }
}
