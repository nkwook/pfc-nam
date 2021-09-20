#include <iostream>
using namespace std;
#include <queue>

int seat[5][5];
int party[7];
queue<pair<int, int> > Q;

int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
int ans=0;
int used[25]={};

int check(){
    int vis[25]={};

    int num=0;
    while(!Q.empty()){
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int t=nx*5+ny;

            if(nx<0 || nx>=5 || ny<0 || ny>=5 ) continue;
            if(vis[t]) continue;
            for(int j=0;j<7;j++){
                if(t==party[j]){
                    // cout << t <<'\n';
                    num++;
                    Q.push(make_pair(nx, ny));
                }
            }
            vis[t]=1;
        }
    }
    if(num==7) return 1;
    else return 0;
}

void backtrack(int k){
    // cout << k <<" ";
    if(k==7){

        int sum=0;
        int x, y;
        for(int i=0;i<7;i++){
            x=party[i]/5;
            y=party[i]%5;
            sum+=seat[x][y];
        }
        // cout <<'\n';
        if(sum>=4){
            // cout << sum <<'\n';
            Q.push(make_pair(x, y));
            if(check()){
                ans++;
            };
        }
        return;
    }
    int st=0;
    if(k>0) st=party[k-1];
    for(int i=st;i<25;i++){
        if(used[i]) continue;

        party[k]=i;
        used[i]=1;
        backtrack(k+1);
        used[i]=0;
    }
    return;
}

int main(){

    for(int i=0;i<5;i++){

        int j=0;
        string s;
        cin >> s;
        for(char c:s){
            if(c=='S'){
                seat[i][j]=1;
            }else{
                seat[i][j]=0;
            }
            j++;
        }
    }
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5;j++){
    //         cout << seat[i][j] << ' ';
    //     }
    //     cout <<'\n';
    // }
    backtrack(0);
    cout << ans;

}