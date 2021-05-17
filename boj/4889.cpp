#include <iostream>
using namespace std;
#include <stack>

int main(){
    int index=0;
    while(true){
        index++;
        string str;
        cin >> str;
        if(str[0]=='-') return 0;

        stack<char> stk;
        int ops=0;
        int final_num=0;

        for(char c: str){
            if(c=='{') stk.push(c);
            else{
                if(!stk.empty() && stk.top()=='{') stk.pop();
                else{
                    stk.push('{');
                    ops++;
                }
            }
        }    
        while(!stk.empty()){
            stk.pop();
            final_num++;
        }    
        cout << index << ". " << ops+final_num/2 << '\n';
    }
}