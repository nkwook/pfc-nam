class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> result(n,vector<int>(n, 0));
      int dx[4]={0, 1, 0, -1};
      int dy[4]={1, 0, -1, 0};

      int elem=1;
      int x=0;
      int y=0;
      int dir=0;
      result[0][0]=1;
      while(elem < n*n){
        int nx=x+dx[dir];
        int ny=y+dy[dir];

        if(nx<0 || nx>=n || ny<0 || ny>=n || result[nx][ny]!=0 ) {
          dir=(dir+1)%4;
          continue;
        }
        elem++;
        
        result[nx][ny]=elem;
        x=nx;
        y=ny;
      }
        
      return result;
    }
};