#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string input[100000];
    int i = 0;
    while (true)
    {
        getline(cin, input[i]);
        if (input[i] == ".")
        {
            break;
        }
        i++;
    }
    // cout << i << '\n';
    for (int k = 0; k < i; k++)
    {
        stack<char> stk;
        int err=0;
        for (char c : input[k])
        {
            if (c == '(' || c == '[')
                stk.push(c);
            else if (c == ')')
            {
                if (stk.empty())
                {
                    err=1;
                    break;
                }
                else if (stk.top() == '(')
                    stk.pop();
                else
                {
                    err=1;
                    break;
                }
            }
            else if (c == ']')
            {
                if (stk.empty())
                {
                    err=1;
                    break;
                }
                else if (stk.top() == '[')
                    stk.pop();
                else
                {
                    err=1;
                    break;
                }
            }
        }
        if (!err && stk.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
}