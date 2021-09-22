#include <iostream>
using namespace std;
#include <queue>
#include <utility>
#include <tuple>

int space[21][21];
int vis[21][21];
int n;
queue < tuple <int, int, int> > Q;
queue <pair<int, int> > FQ; 
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // int status;
            cin >> space[i][j];
            vis[i][j]=0;
            if(space[i][j]==9){
                space[i][j]=0;
                vis[i][j]=1;
                Q.push(make_tuple(i, j, 0));
            }
        }
    }

    int ans=1; // to use on vis
    int size=2;
    int fish=0;
    while(true){
        // cout << ans <<'\n';
        // // int time=0;
        // for(int p=0;p<n;p++){
        //     for(int q=0;q<n;q++){
        //         cout << space [p][q] << " ";
        //     }
        //     cout << '\n';
        // }
        if(size*(size+1)/2-1 <= fish) size++;


        while(!FQ.empty()){
            FQ.pop();
        }
        bool tFlag=0;
        int eFlag=0;
        while(!Q.empty()){
            int x=get<0>(Q.front());
            int y=get<1>(Q.front());
            int d=get<2>(Q.front());
            // cout << x << " " << y << " " << d << '\n';
            Q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                int nd=d+1;
                // cout << nx << " " << ny << " " << nd << '\n';

                if(nx<0 || nx>=n || ny<0 || ny>=n ) continue;
                if(vis[nx][ny]==ans) continue; // could be changed
                if(eFlag && eFlag < nd ) continue;
                
                vis[nx][ny]=ans;
                if(space[nx][ny]>0 && space[nx][ny]<size){
                    // cout << nx << " " << ny << " " << vis[nx][ny] << '\n';
                    FQ.push(make_pair(nx, ny));
                    eFlag=nd;
                    // size++;
                }else if(eFlag || space[nx][ny] > 6 || space[nx][ny] > size){
                    continue;
                }
                // zero or same as shark, more to go
                Q.push(make_tuple(nx, ny, nd));
            }            
        }
        //determine what to eat
        if(FQ.empty()){
            cout << ans-1 ;
            return 0;
        }
        
        int mindex=999;
        while(!FQ.empty()){
            int x=FQ.front().first;
            int y=FQ.front().second;
            FQ.pop();
            int m=n*x+y;

            // cout << x << " " << y <<'\n';
            if(mindex>m) mindex=m;
        }
        int nx=mindex/n;
        int ny=mindex%n;
        space[nx][ny]=0;
        Q.push(make_tuple(nx, ny, 0));
        fish++;
        ans+=eFlag;

    }



}