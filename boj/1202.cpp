#include <iostream>
using namespace std;
#include <map>
#include <set>
#include <utility>

//ahh type...

multimap<int, int> jewelry;
multiset<int> bag;
int n, k;
int m, v, c;

int main()
{
    cin >> n >> k;
    long long total = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> m >> v;
        jewelry.insert(make_pair(v, m));
    }

    for (int i = 0; i < k; i++)
    {
        cin >> c;
        bag.insert(c);
    }

    while (!bag.empty() && !jewelry.empty())
    {
        auto target = prev(jewelry.end());
        auto selected = bag.lower_bound(target->second
        );
      
        if (selected != bag.end())
        {
            total+= target->first;
            bag.erase(selected);
        }

        jewelry.erase(target);
    }

    cout << total;
}
