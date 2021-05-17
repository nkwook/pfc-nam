#include <iostream>
using namespace std;
#include <stack>

int innerStack(stack<int>& st, int id){
    while(true){
        int top=st.top();
        st.pop();
        // cout << top;
        if(st.empty()){
            st.push(top);
            break;
        }
        else if(st.top()==id){
            st.pop();
            st.push((id+2)*top);
            // cout << st.top();
        }else if(st.top()>1){
            int top2=st.top();
            st.pop();
            st.push(top2+top);
        }
    }

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string input;
    cin >> input;
    stack<int> st;
    stack<int> result_stack;
    int var=1;
    int result=0;

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
                st.push(top);
                innerStack(st, 0); 
            }else{
                cout << 0;
                return 0;
            }
            // }
        } 
        else if (c == ']')
        {
            int top=st.top();
                st.pop();
            if(top==1){
                st.push(3);
            }else if(top>=2){
                st.push(top);
                innerStack(st, 1); 
            }else{
                cout << 0;
                return 0;
            }  
        }else{
            cout << 0;
            return 0;
        }

     
    }

    while(!st.empty()){
        result+=st.top();
        st.pop();
    }

    cout << result;
}