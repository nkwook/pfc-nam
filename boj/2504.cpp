#include <iostream>
using namespace std;
#include <stack>

int main()
{
    string input;
    cin >> input;
    stack<int> stk;
    for (char c : input)
    {
        if (c == '('){
            stk.push(0);
        }else if( c == '['){
            stk.push(1);
        }
        else
        {
            while (true)
            {
                // cout << stk.top() <<" qqqq\n";
                if (stk.empty())
                {
                    cout << 0;
                    return 0;
                }

                if (c == ')')
                {
                    if (stk.top() == 1)
                    {
                        cout << 0;
                        return 0;
                    }
                    else if (stk.top() == 0)
                    {
                        // cout << "??\n";
                        stk.pop();
                        stk.push(2);
                        c='a';
                    }
                    else
                    {
                        int x = stk.top();
                        stk.pop();
                        if(stk.empty()){
                            cout << 0;
                            return 0;

                        }
                        else if (stk.top() == 0)
                        {
                            stk.pop();
                            stk.push(2 * x);
                            c='a';

                        }
                        else
                        {
                            cout << 0;
                            return 0;
                        }
                    }
                }
                else if (c == ']')
                {
                    if (stk.top() == 0)
                    {
                        cout << 0;
                        return 0;
                    }
                    else if (stk.top() == 1)
                    {
                        // cout << "dsfadsfadf\n";
                        stk.pop();
                        stk.push(3);
                        // cout << stk.top() << '\n';
                        c='a';

                    }
                    else
                    {
                        // cout << "come?\n";
                        int x = stk.top();
                        stk.pop();
                        if(stk.empty()){
                            cout << 0;
                            return 0;

                        }
                        else if (stk.top() == 1)
                        {
                            stk.pop();
                            stk.push(3 * x);
                            c='a';
                        }
                        else
                        {
                            cout << 0;
                            return 0;
                        }
                    }
                }
                else if(c=='a')
                {
                    // cout << "dasfa\n";
                    int x = stk.top();
                    stk.pop();
                    if (stk.empty())
                    {
                        // cout << "asdfdf\n";
                        stk.push(x);
                        break;
                    }
                    else if (stk.top() == 0 || stk.top() == 1)
                    {
                        stk.push(x);
                        break;
                    }
                    else
                    {
                        int x2 = stk.top();
                        stk.pop();
                        stk.push(x + x2);
                        break;
                    }
                }else{
                    cout << 0;
                    return 0;
                }
            }
        }
    }
    if(stk.empty() || stk.top()==0 || stk.top()==1){
        cout << 0;
    } else{
        cout << stk.top();

    }
}
