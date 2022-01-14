class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> Q;
        int sx=grid.size();
        int sy=grid[0].size();
        
        int dx[4]={1, 0, -1, 0};
        int dy[4]={0, 1, 0, -1};
        bool vis[sx][sy];
        
        for(int i=0;i<sx;i++){
            for(int j=0;j<sy;j++){
                vis[i][j]=false;
            }
        }
        
        
        int cnt=0;
        for(int i=0;i<sx;i++){
            for(int j=0;j<sy;j++){
                int size=0;
                
                if(!vis[i][j] && grid[i][j]=='1' ){
                    Q.push({i, j});
                    size++;
                }
                vis[i][j]=true;
                while(!Q.empty()){
                    pair<int, int> front=Q.front();
                    Q.pop();
                    int x=front.first;
                    int y=front.second;
                    for(int dir=0;dir<4;dir++){
                        int nx=x+dx[dir];
                        int ny=y+dy[dir];
                        if(nx<0 || nx>=sx || ny <0 || ny>=sy) continue;
                        if(vis[nx][ny] || grid[nx][ny]!='1') continue;
                        
                        Q.push({nx, ny});
                        vis[nx][ny]=true;
                        size++;
                    }
                }
                if(size>0) cnt++;
            }
        }
        return cnt;
            
        
    }
};