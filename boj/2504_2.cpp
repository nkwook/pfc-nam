#include <iostream>
using namespace std;
#include <stack>

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    cin >> input;
    stack<int> st;
    stack<int> result_stack;
    int var=1;
    // int result=0;

    for (char c : input)
    {
        if (c == '('){
            st.push(0);
        }else if( c == '['){
            st.push(1);
        }
        else if (c == ')'){
            int top=st.top();
            st.pop();
            if(top==0){
                st.push(2);
            }else if(top>=2){
                
            }
        } 
        else if (c == ']' && st.top() == 1)
        {
            var *= 3;
            st.pop();
        }else 
        
        
        else{
            cout << 0;
            return 0;
        }

        // if(st.empty()){
        //     result_stack.push(var);
        //     var=1;
        // }
    }

    while(!result_stack.empty()){
        result+=result_stack.top();
        result_stack.pop();
    }

    cout << result;
}