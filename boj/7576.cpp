#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define X first
#define Y second

int main(){
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};
    
    int n, m;
    cin >> m >> n;
    int box[n][m];

    queue <pair<int, int>> Q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tomato;
            cin >> tomato;
            
            box[i][j]=tomato;
            if(tomato==1){
                Q.push({i, j});
            }
        }
    }
    
    while(!Q.empty()){
        int x=Q.front().X;
        int y=Q.front().Y;
        Q.pop();
        // cout << x << " " << y << " " << box[x][y] << "\n";
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(box[nx][ny]!=0) continue;
            box[nx][ny]=box[x][y]+1;
            // cout << nx << " " << ny << " " << box[nx][ny] << "\n";

            Q.push({nx, ny});
        }

    }

    int max=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(box[i][j]==0){
                cout << -1;
                return 0;
            }
            if(max < box[i][j]-1){
                max=box[i][j]-1;
            }
        }
    }

    cout << max;

}