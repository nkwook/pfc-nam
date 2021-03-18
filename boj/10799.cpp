#include <iostream>
using namespace std;
// #include <stack>

int main(){
    string input;
    cin >> input;
    stack<int> stk;
    int s=0;
    int result=0;
    int combo=0;

    for(char c: input){
        if(c=='('){
            combo=0;
            s++;
        }else if(c==')'){
            if(!combo){
                s--;
                result+=s;
                combo++;
            }else{
                s--;
                result++;
            }
        }
    }
    cout << result;
}