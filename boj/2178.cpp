#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define X first
#define Y second

int main(){
    int x, y;
    cin >> x >> y;
    int maze[x][y];
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    queue<pair<int, int> > Q;

    int distance[x][y];

    for(int i=0;i<x;i++){
        string str;
        cin >> str;
        int j=0;
        for(char c: str){
            maze[i][j]=(int)c-'0';
            distance[i][j]=0;
            j++;
        }
    }
    // cout << maze[0][1];

    // bfs starts from 0,0 
    Q.push({0,0});
    

    while(!Q.empty()){
        // strategy to get shortest.
        // gonna compare, if longer => dont go
        pair<int, int> point=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int nx=point.X+dx[i];
            int ny=point.Y+dy[i];
            // cout << nx << " " << ny << "\n";
            if(nx<0||nx>=x||ny<0||ny>=y) continue;
            if(!maze[nx][ny]) continue;
            if(distance[nx][ny]) continue;
            // reason that is shortest => 
            // to be inverted, going upward/left has to be needed but
            // it means distance gets longer and we already have the shortest
            distance[nx][ny]=distance[point.X][point.Y]+1;
            Q.push({nx, ny});
     
        }
    }

    cout << distance[x-1][y-1]+1;


}