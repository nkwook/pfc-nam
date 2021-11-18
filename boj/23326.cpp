#include <iostream>
using namespace std;
#include <set>

int n, q;
int temp;
set<int> a;
int category;

int diff(int s, int p)
{
    if (p > s)
        return n-p+s;
    else
        return s - p;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp)
        {
            a.insert(i);
        }
    }

    int position = 0;
    int i, x;
    while (q--)
    {
        cin >> category;

        // cout << "seq" << '\n';
        // for(auto it=a.begin();it!=a.end();it++){
        //     cout << *it << ' ';

        // }
        // cout << '\n';

        if (category == 1)
        {
            int i;
            cin >> i;
            auto it = a.find(i-1);
            if (it != a.end())
            {
                a.erase(it);
            }
            else
            {
                a.insert(i-1);
            }
        }
        else if (category == 2)
        {
            int x;
            cin >> x;
            position = (position + x) % n;
        }
        else
        {
            if (a.empty())
            {
                cout << -1 <<'\n';
                continue;
            }
            auto spot = a.lower_bound(position);
            // cout << *spot <<'\n';
            if(spot==a.end() ){
                spot=a.begin();
            }            
            cout << diff(*spot,position)  << '\n';
        }
    }
}

