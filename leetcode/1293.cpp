class Solution {
public:
  int shortestPath(vector<vector<int>> &grid, int k) {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int m = grid.size();
    int n = grid[0].size();
    int vis[m][n];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        vis[i][j] = -1;
      }
    }

    // k, x, y
    queue < tuple<int, int, int, int> >Q;
    int result=100000000;
    Q.push({k, 0, 0, 0});
    vis[0][0]=k;

    while (!Q.empty()) {
      tuple<int, int, int, int> t = Q.front();
      Q.pop();

      int tk = get<0>(t);
      int tx = get<1>(t);
      int ty = get<2>(t);
      int tLength = get<3>(t);
    //   cout << tk  << ' ' << tx << ' ' << ty << ' ' << tLength << ' ' << vis[tx][ty] <<'\n';

      if( tx==m-1 && ty==n-1){
        if (result > tLength){
          result=tLength;
        }
        continue;       
      }

      for (int i = 0; i < 4; i++) {
        int nx = tx + dx[i];
        int ny = ty + dy[i];
        int nk = tk;

        if (nx >= m || nx < 0 || ny >= n || ny < 0)
          continue;
        if (grid[nx][ny] == 1 && tk <= 0)
          continue;
        if (grid[nx][ny] + vis[nx][ny] >= tk)
          continue;
        // 거리에서는 불리하지만 폭탄을 더 많이 가지고 있는 경우 고려
        // vis 배열에 남은 폭탄수를 저장

        if (grid[nx][ny] == 1) {
          nk--;
        } 
        vis[nx][ny] = nk;
        
        int nLength = tLength + 1;
        Q.push({nk, nx, ny, nLength});
      }
    }
    if (result==100000000) return -1;
    return result;
  }
};