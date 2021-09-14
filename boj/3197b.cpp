#include <iostream>
#include <queue>
using namespace std;
#include <utility>
#include <vector>

/*
    doing bfs everyday? no...

    we will make map of melting days, and do binary search
    good!!!

    But also have to observe other solutions.
*/

int lake[1501][1501];
int clake[1501][1501];
int vis [1501][1501];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};

queue<pair <int, int> > Q;
// queue<pair <int, int> > NQ;
vector<pair<int, int> > LV;

int vis2 [1501][1501] ;
int r, c;

int check(int d){

    while(!Q.empty()){
        Q.pop();
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            clake[i][j]=lake[i][j]-d;
        }
    }
    
    Q.push(make_pair(LV[0].first, LV[0].second));

    while(!Q.empty()){
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();

        for(int dir=0;dir<4;dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];

            if(nx<0 || nx>=r || ny<0 || ny>=c || vis2[nx][ny]==d) continue;
            if(clake[nx][ny]>0) continue;
            
            if(nx==LV[1].first && ny==LV[1].second){
                return 1;
            }

            vis2[nx][ny]=d;
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
            if(ch=='X'){
                lake[i][j]=-1;
            }
            else if(ch=='.'){
                lake[i][j]=0;
            }
            else if(ch=='L'){// store swan position
                lake[i][j]=0;
                LV.push_back(make_pair(i, j));
            }
            j++;
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(lake[i][j]==0) continue;
            int min=30000;
            
            for(int dir=0;dir<4;dir++){
                int nx=i+dx[dir];
                int ny=j+dy[dir];

                if(nx<0 || nx>=r || ny<0 || ny>=c || lake[nx][ny]==-1) continue;

                if(min > lake[nx][ny]) min=lake[nx][ny];

            }            
            lake[i][j]=min+1;
        }
    }
    for(int i=r-1;i>=0;i--){
        for(int j=c-1;j>=0;j--){
            if(lake[i][j]==0) continue;
            int min=30000;
            
            for(int dir=0;dir<4;dir++){
                int nx=i+dx[dir];
                int ny=j+dy[dir];

                if(nx<0 || nx>=r || ny<0 || ny>=c || lake[nx][ny]==-1) continue;

                if(min > lake[nx][ny]) min=lake[nx][ny];

            }            
            lake[i][j]=min+1;
        }
    }
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout << lake[i][j] << " " ;
    //     }
    //     cout << '\n';
    // }
    int st=0;
    int en=3000;

    while(st<en){
        
        int mid=(st+en)/2;

        int result=check(mid);
        if(result){
            en=mid;
        }else{
            st=mid+1;
        }

    }

    cout << st;
    
        
        
}