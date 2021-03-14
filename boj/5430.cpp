#include <iostream>
using namespace std;
#include <deque>
#include <string.h> //needed...

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    while (T)
    {
        string p;
        int n;
        // string input;
        cin >> p;
        cin >> n;

        char input[4 * n + 100]; //we have to consider size... fuck ! 
        cin >> input;
        deque<string> deq;
        int rmode = 0;
        int err = 0;
 
        // hmm lets found c++ way to parse
        // time over... attempt to make mods
        char *pch = strtok((char *)input, ",[]");
        while (pch != NULL)
        {
            deq.push_back(pch);
            pch = strtok(NULL, ",[]");
        }

        for (char c : p)
        {
            if (c == 'R')
            {
                if (rmode)
                {
                    rmode = 0;
                }
                else
                {
                    rmode = 1;
                }
            }
            else if (c == 'D')
            {
                if (deq.empty())
                {
                    err = 1;
                    break;
                }
                else
                {
                    if (!rmode)
                    {
                        deq.pop_front();
                    }
                    else
                    {
                        deq.pop_back();
                    }
                    n--;
                }
            }else{
                err=1;
                break;
            }

            // cout << c << '\n';
            // for (int i = 0; i < deq.size(); i++)
            // {
            //     cout << deq[i] << ',';
            // }
        }
        if (err)
        {
            cout << "error\n";
        }
        else
        {
            cout << '[';
            while (!deq.empty())
            {
                if (!rmode)
                {
                    cout << deq.front();
                    deq.pop_front();
                }
                else
                {
                    cout << deq.back();
                    deq.pop_back();
                }

                if (deq.empty())
                {
                    break;
                }
                cout << ',';
            }
            cout << "]\n";
        }
        T--;
    }
}