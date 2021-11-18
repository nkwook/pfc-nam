#include <iostream>
using namespace std;
#include <set>

int t;
int k;
char c;
int num;
multiset<int> s;

//erase method both applicable to either it, value
// need to use multiset!

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;

    while (t--)
    {
        cin >> k;

        while (k--)
        {
            cin >> c >> num;
            if (c == 'I')
            {
                s.insert(num);
            }
            else
            {
                if(s.empty()) continue;
                if (num > 0)
                {
                    s.erase(prev(s.end()));
                }
                else
                {
                    s.erase(s.begin());
                }
            }
        }
        if (s.empty())
            cout << "EMPTY\n";
        else
        {
            cout << *prev(s.end()) << ' ' << *s.begin() <<'\n';

            while(!s.empty()){
                s.erase(s.begin());
            }
        }
    }
}