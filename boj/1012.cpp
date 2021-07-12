#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define X first;
#define Y second;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

/* ahh fucking spacing... */

int main()
{
    int t, m, n, k;
    cin >> t;

    
    for (int a = 0; a < t; a++)
    {

        cin >> m >> n >> k;
        int result = 0;

        int map[m][n];
        int vis[m][n];
    
        for (int i = 0; i <m ; i++)
        {
            for (int j = 0; j < n; j++)
            {
                map[i][j]=0;
                vis[i][j]=0;
            }
        }


        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;

            map[x][y] = 1;
        }

        queue<pair<int, int>> Q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // check whether bfs or not
                if (vis[i][j] || !map[i][j])
                    continue; //initialize?

                vis[i][j] = 1;
                Q.push({i, j});
                result++;

                while (!Q.empty())
                {
                    int x = Q.front().X;
                    int y = Q.front().Y;
                    // cout << x << " ," << y << '\n';
                    Q.pop();

                    for (int l = 0; l < 4; l++)
                    {
                        int nx = x + dx[l];
                        int ny = y + dy[l];

                        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                            continue;
                        
                        if (map[nx][ny] && !vis[nx][ny])
                        {
                            Q.push({nx, ny});
                        }
                        vis[nx][ny] = 1;

                   
                    }
                }
            }
        }

        cout << result << "\n";
    }
}