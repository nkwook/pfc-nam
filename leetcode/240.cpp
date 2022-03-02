class Solution { // O(nlgn)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(int i=0;i<m;i++){
            if(bSearch(0, n-1, matrix[i], target)) return true;
        }    
        return false;
    }
    bool bSearch(int start, int end, vector<int>& vec, int t){
        if(start+1 >=end){
            if(vec[start]==t || vec[end]==t) return true; 
            else return false;
        }
        int mid=(start+end)/2;
        if(vec[mid]==t){
            return true;
        }
        else if(vec[mid]<t){
            return bSearch(mid, end, vec, t);
        }else{
            return bSearch(start, mid, vec, t);
        }
        
        
        
    }
      
};

class Solution { // wow top-right approach.....
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int x=0;
        int y=n-1;
        while(x<m && y>=0){
            
            if(matrix[x][y]==target){
                return true;
            }else if(matrix[x][y] < target){
                x++;
            }else y--;
        }
        return false;        
    }    
    
};


class Solution { // trash m+n
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int dx[4]={0, 1, 0, 1};
        int dy[4]={1, 0, -1, 0};
        
        int dir=0;
        int x=0;
        int y=0;
        int cnt=0;
        while(true){
            // cout << x << ' ' << y << '\n';
            if(matrix[x][y]==target) return true;
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx<0 || nx>=m || ny<0 || ny>=n){
                dir=(dir+1)%4;
                cnt++;
                if(cnt>2) return false;
                continue;
            }
            if(matrix[nx][ny]>target){
                dir=(dir+1)%4;
                cnt++;
                if(cnt>2) return false;
                continue;
            }
            if(dir==2 && matrix[nx][ny]<target){
                dir=1;
                x=nx;
                y=ny;
                continue;
            }
            x=nx;
            y=ny;
            cnt=0;
        }
        return false;   
    }    
    
    
};