class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
      int dx[4]={1, 0, -1, 0};
      int dy[4]={0, 1, 0, -1};
        
      vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), -1));
      queue<pair<int, int>> Q;
      Q.push({entrance[0], entrance[1]});
      maze[entrance[0]][entrance[1]]='0';
      distance[entrance[0]][entrance[1]]=0;
        
      while(!Q.empty()){

          
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();
        

        if(x==0 || x==maze.size()-1 || y==0 || y==maze[0].size()-1){
          if(distance[x][y]>0){
            return distance[x][y];
          }
        }

        for(int i=0;i<4;i++){
          int nx=x+dx[i];
          int ny=y+dy[i];

          if(nx<0 || nx>=maze.size() || ny<0 || ny>=maze[0].size()) continue;
          if(maze[nx][ny]!='.' || distance[nx][ny]>-1) continue;

          distance[nx][ny]=distance[x][y]+1;                  
          Q.push({nx, ny});
          
        }

      }

      return -1;
      
      

      
    }
};