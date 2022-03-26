class Solution { // TLE, O(M*N*min(M, N)^2)
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int length=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                length=max(length, getMaxLen(i, j, matrix));
            }
        }
        return length*length;
    }
    
    int getMaxLen(int x, int y, vector<vector<char>> &m){
        int constraintLen=min(m.size()-x, m[0].size()-y);
        int maxLen=0;
        int j=0;
        for(int i=0;i<constraintLen;i++){
            for(j=0;j<constraintLen && m[x+i][y+j]!='0'; j++){    
            }
            constraintLen=j;
            maxLen=min(constraintLen, i+1);
        }
        return maxLen;
    }
};

class Solution { // dp inline. char overflow?
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int result=0;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 || j==n-1){
                    matrix[i][j]= matrix[i][j]=='1' ? 1 : 0;
                }else{
                    matrix[i][j]=matrix[i][j]=='1'? 
                        1+ min({matrix[i][j+1], matrix[i+1][j], matrix[i+1][j+1]})     
                        : 0 ;           
                }
                result=max(result, int(matrix[i][j]));
            }
        }
        return result*result;
    }
};


class Solution { // TC O(MN), SC O(MN)
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int> > dp(m+1, vector<int>(n+1));
        
        int result=0;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 || j==n-1){
                    dp[i][j]= matrix[i][j]=='1' ? 1 : 0;
                }else{
                    dp[i][j]=matrix[i][j]=='1'? 
                        1+ min({dp[i][j+1], dp[i+1][j], dp[i+1][j+1]})     
                        : 0 ;           
                }
                result=max(result, dp[i][j]);
            }
        }
        return result*result;
    }
};

