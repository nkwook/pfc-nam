class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 1650~
        // brute force?
        // 9*(9+9+9); 
        // tradeoff between sp, tc
        vector<bool> v(9, false);
        
        for(int i=0;i<9;i++){
            for(int k=0;k<9;k++) v[k]=false;
            
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(v[board[i][j]-'1']) return false;
                
                v[board[i][j]-'1']=true;
            }
        }
        
        for(int i=0;i<9;i++){
            for(int k=0;k<9;k++) v[k]=false;
            
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                if(v[board[j][i]-'1']) return false;
                
                v[board[j][i]-'1']=true;
            }
        }
        
        for(int i=0;i<9;i++){
            for(int k=0;k<9;k++) v[k]=false;
            
            int x=(i/3)*3;
            int y=(i%3)*3;
            for(int j=0;j<9;j++){
                int xi=x+j/3;
                int yi=y+j%3;
                if(board[xi][yi]=='.') continue;
                if(v[board[xi][yi]-'1']) return false;
                
                v[board[xi][yi]-'1']=true;
            }
        }
        return true;
        
        
    }
};