#include <iostream>
using namespace std;
#include <stack>

int verify(string str){
    stack<char> stk;

    for(char c: str){
        if(c=='('){
            stk.push(c);
        }else if(c==')'){
            if(stk.empty()) return 0;
            else{
                stk.pop();
            }
        }
    }
    if(!stk.empty()) return 0;
    else return 1;
}


int main(void){
    int num;
    // string str[num];
    cin >> num;
    for(int i=0;i<num;i++){
        string str;
        cin >> str;
        if(verify(str)){
            cout << "YES\n";
        }else cout << "NO\n";
    }    

}


