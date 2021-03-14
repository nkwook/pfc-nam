#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int n, m;
    int result = 0;
    cin >> n >> m;
    vector<int> target;
    // to preserve order, we have to get input at once and use stl vector
    // fuck... let try to think as 'rule'
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        target.push_back(t);
    }
    while (m)
    {
        int x = target[0];
        // cout << x << ", ";
        if (n - x >= n / 2)
        {
            result += (x - 1);
        }

        else
        {
            result += (n - x + 1);
        }

        for (int &j : target)
        {
            // cout  << j << "j";
            if (j > x)
            {
                j -= x;
            }
            else
            {
                j += (n - x);
            }
        }
        // cout << '\n';
        target.erase(target.begin());

        // cout << '\n';
        n--;
        m--;
    }

    cout << result;
}
