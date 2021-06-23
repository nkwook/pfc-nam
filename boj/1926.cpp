#include <iostream>
using namespace std;
#include <utility>
#include <queue>

#define X first
#define Y second
 //flood fill
int main()
{
    //bfs implementation
    int n, m;
    cin >> n >> m;
    int paper[n][m];
    int vis[n][m];
    queue<pair<int, int> > Q;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int max_size=0;
    int picture_num=0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> paper[i][j];
            vis[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //try bfs for each point
            int size=0;
//bfs starting point has to be a picture pt
            if(!vis[i][j] && paper[i][j]){ 
                vis[i][j]=1;
                Q.push({i, j});
                size++;
            }

            while(!Q.empty()){
                pair<int, int> point=Q.front();
                // cout << point.X << " " << point.Y;
                Q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx=point.X+dx[dir];
                    int ny=point.Y+dy[dir];
                    // cout << nx << ny << '\n';
                    if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                    if(vis[nx][ny] || paper[nx][ny] !=1) continue;

                    // cout << "!!!";
                    vis[nx][ny]=1;
                    Q.push({nx, ny});
                    size++;

                }

            }
            if(size) picture_num++;
            if(size>max_size) max_size=size;

        }
    }

    cout << picture_num << '\n';
    cout << max_size ;
}