#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define X first
#define Y second

/* 
    Cautions
    Needs to take care of all possible letters/strings
    When man is on board, or fire cant reach all area

*/

int main(){

    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};

    int r, c;
    cin >> r >> c;
    string mazeJ[r][c];
    string mazeF[r][c];
    queue<pair<int, int>> FQ;
    queue<pair<int, int>> JQ;

    for(int i=0;i<r;i++){
        string map;
        cin >> map;
        int j=0;
        for(char c: map){
            mazeJ[i][j]=c;
            mazeF[i][j]=c;
            if(c=='F'){
                FQ.push({i, j});
            }else if(c=='J'){
                JQ.push({i, j});
            }
            j++;
        }
    }

    /* Strategy: make 2 maps, compare time distance
     */
    
    // cout << distance << "fd\n";

    while(!JQ.empty()){
        int x=JQ.front().X;
        int y=JQ.front().Y;

        JQ.pop();
        

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0 || nx>=r || ny<0 || ny>= c) continue;
            if(mazeJ[nx][ny]!=".") continue;

            if(mazeJ[x][y]=="J") mazeJ[nx][ny]=to_string(1);
            else mazeJ[nx][ny]=to_string(stoi(mazeJ[x][y])+1);

            JQ.push({nx, ny});
        }
    }

    // cout mazeJ

    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout << mazeJ[i][j];
    //     }
    //     cout << '\n';
    // }
    
    // cout << '\n';

    // cout << distance << "fd\n";

    while(!FQ.empty()){
        int x=FQ.front().X;
        int y=FQ.front().Y;

        FQ.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<0 || nx>=r || ny<0 || ny>= c) continue;
            if(mazeF[nx][ny]!=".") continue;

            if(mazeF[x][y]=="F") mazeF[nx][ny]=to_string(1);
            else mazeF[nx][ny]=to_string(stoi(mazeF[x][y])+1);

            FQ.push({nx, ny});
        }
    }

    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout << mazeF[i][j];
    //     }
    //     cout << '\n';
    // }
    
    int success=0;
    int time=0;

    for(int i=0;i<r;i++){ 
        for(int j=0;j<c;j++){
            if(mazeJ[i][j]=="#" || mazeJ[i][j]=="F" || mazeJ[i][j]=="." ) continue;

            if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
            {
                if (mazeJ[i][j] == "J")
                {
                    cout << 1;
                    return 0;
                }
                int x = stoi(mazeJ[i][j]); // aha...
                //불막힌경우
                int y;
                if(mazeF[i][j]=="."){
                    y=0;
                }else y = stoi(mazeF[i][j]);

                if(!y || x<y && (!time || x<time)){
                    success++;
                    time=x;
                }
            }
        }
    }

    if(success) cout << time+1;
    else cout << "IMPOSSIBLE";

}


