#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
using namespace std;

// using tuple...

int main(){
    int dx[6]={1, 0, -1, 0, 0, 0};
    int dy[6]={0, -1, 0, 1, 0, 0};
    int dz[6]={0, 0, 0, 0, 1, -1};

    // we cant use pair... then? => arr.
    
    queue<tuple<int, int, int>> Q;
    int m, n, h;
    cin >> m >> n >> h;
    int box[h][n][m];
    int already=1;
    
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int t;
                cin >> t;
                box[k][i][j]=t;
                if(t==1){
                    Q.push(make_tuple(j, i, k));
                }else if(t==0){
                    already=0;
                }
            }
        }
    }
    if(already){
        cout << 0;
        return 0;
    }

    while(!Q.empty()){
        int x=get<0>(Q.front());
        int y=get<1>(Q.front());
        int z=get<2>(Q.front());

        Q.pop();

        for(int i=0;i<6;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nz=z+dz[i];

            if(nx<0 || nx>=m || ny<0 || ny>=n || nz<0 || nz>=h) continue;
            if(box[nz][ny][nx]!=0) continue;

            box[nz][ny][nx]=box[z][y][x]+1;
            Q.push({nx, ny, nz});
        }
    }

    int max=0;
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(box[k][i][j]==0){
                    cout << -1;
                    return 0;
                }
                if(max<box[k][i][j]-1){
                    max=box[k][i][j]-1;
                }
            }
        }
    }

    cout << max;

}