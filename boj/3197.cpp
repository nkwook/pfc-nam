#include <iostream>
#include <queue>
using namespace std;
#include <utility>
#include <vector>

/*
    doing bfs everyday? no...

    actually making distance map is kind of hard
    just make sure to keep next ice blocks in buffer queue

*/

char lake[1501][1501];
int vis [1501][1501];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

queue<pair <int, int> > Q;
queue<pair <int, int> > NQ;
vector<pair<int, int> > LV;

int vis2 [1501][1501] ;
int r, c;

int check(){

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            vis2[i][j]=0;
        }
    }
    // for()
    Q.push(make_pair(LV[0].first, LV[0].second));

    while(!Q.empty()){
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();

        for(int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            // cout << nx <<" " << ny << "  " << "45\n";

            if(nx<0 || nx>=r || ny<0 || ny>=c || vis2[nx][ny]) continue;
            if(lake[nx][ny]=='X') continue;
            
            if(nx==LV[1].first && ny==LV[1].second){
                return 1;
            }


            vis2[nx][ny]=1;
            Q.push(make_pair(nx, ny));
        }
    }
    return 0;
}


int main(){
    cin >> r >> c;    

    for(int i=0;i<r;i++){
        string str;

        cin >> str;
        int j=0;
        for(char ch:str){
            lake[i][j]=ch;
            if(ch=='L'){// store swan position
                LV.push_back(make_pair(i, j));
            }
            j++;
        }
    }


    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(lake[i][j]=='X' || vis[i][j]) continue;

            Q.push(make_pair(i, j));
            while(!Q.empty()){
                int x=Q.front().first;
                int y=Q.front().second;
                // cout << x << " " << y << " !" <<'\n';
                Q.pop();

                for(int dir=0;dir<4;dir++){
                    int nx=x+dx[dir];
                    int ny=y+dy[dir];

                    if(nx<0 || nx>=r || ny<0 || ny>=c || vis[nx][ny]) continue;
                    // if(lake[nx][ny]!=-1) continue;

                    vis[nx][ny]=1;
                    // cout << nx << " " << ny << " " << lake[nx][ny] <<'\n';
                    if(lake[nx][ny]=='X'){
                        // cout << "XXXXX\n";
                        NQ.push(make_pair(nx, ny));
                    }else{
                        Q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }

    // after this... check ability to meet,
    // make 2 queues switch

    // cout << NQ.size();
    int days=0;
    while(true){
        if(check()){
            cout << days ;
            return 0;
        }
        days++;

        while(!Q.empty()){
            Q.pop();
        }

        // cout << "??"  <<  NQ.size() << '\n';
        //or using tuples? hmm...
        while(!NQ.empty()){ // to generalize operation
            int x=NQ.front().first;
            int y=NQ.front().second;

            // cout << x << " " << y <<" " << 140 <<'\n';
            lake[x][y]='.';
            Q.push(NQ.front());
            NQ.pop();
        }
        // cout <<"???\n";

        //pick up next ones
        while(!Q.empty()){
            int x=Q.front().first;
            int y=Q.front().second;
            Q.pop();
            // cout << x << " " << y << " 152\n"; 
            for(int dir=0;dir<4;dir++){
                int nx=x+dx[dir];
                int ny=y+dy[dir];

                if(nx<0 || nx>=r || ny<0 || ny>=c  || vis[nx][ny]) continue;
                if(lake[nx][ny]=='.' || lake[nx][ny]=='L') continue;

                vis[nx][ny]=1;
                NQ.push(make_pair(nx, ny));
            }
        }

        // cout << days << '\n';
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout << lake[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

    }
        
        
}