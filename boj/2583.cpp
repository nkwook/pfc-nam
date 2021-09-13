#include <iostream>
using namespace std;
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>


int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};


int map[101][101];
int vis[101][101];
vector<int> area;

int m, n, k;
queue< pair<int, int> > Q;


int main(){
    cin >> m >> n >> k;

    for(int i=0;i<k;i++){
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;
        for(int x=x1;x<x2;x++){
            for(int y=y1;y<y2;y++){
                map[x][y]=1;
            }
        }
    }


    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << map[i][j] << " ";
    //     }
    //     cout << '\n';
    // }


    int num=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] || map[i][j]==1) continue;
            // cout << i << " " << j <<'\n';
            Q.push(make_pair(i, j));
            vis[i][j]=1;
            num++;

            int areaTemp=1;
            
            while(!Q.empty()){
                int x=Q.front().first;
                int y=Q.front().second;
                
                Q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx=x+dx[dir];
                    int ny=y+dy[dir];

                    if(nx<0 || nx>=n || ny <0 || ny>=m || vis[nx][ny]) continue;
                    if(map[nx][ny]==1) continue; 

                    areaTemp++;
                    Q.push(make_pair(nx, ny));
                    vis[nx][ny]=1;
                }
            }

            area.push_back(areaTemp);

        }
    }

    sort(area.begin(), area.begin()+num);
    cout << num << '\n';
    for( int i:area){
        cout << i << ' ';
    }

}
