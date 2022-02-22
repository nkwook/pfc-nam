#include <iostream>
using namespace std;

int n;
int arr[21][21];
int ans[21][21] = {};
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            bool exist = true;
            for (int k = 1; k <= n; k++)
            {
                if (i == j || j == k || i == k)
                    continue;

                if (arr[i][j] == arr[i][k] + arr[k][j])
                {
                    exist = false;
                    break;
                }
                else if (arr[i][j] > arr[i][k] + arr[k][j])
                {
                    cout << -1;
                    return 0;
                }
            }
            if (exist)
            {
                ans[i][j] = arr[i][j];
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            sum += ans[i][j];
        }
    }
    cout << sum;
    return 0;
}