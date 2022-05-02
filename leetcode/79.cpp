class Solution { // wow using substr(1)......
public:
    bool exist(vector<vector<char>>& board, string word) {
        string w=word.substr(1);

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(rec(board, i, j, word)) return true;
            }
        }
        return false;
    }
    
    bool rec(vector<vector<char>>& board, int x, int y, string &word){
        int dx[4]={1, 0, -1, 0};
        int dy[4]={0, 1, 0, -1};
        if(!word.size()) return true;
        
        if(x>=board.size() || x<0 || y>=board[0].size() || y<0 || board[x][y]!=word[0]) return false;
        char c=board[x][y];
        board[x][y]='.';    
        string w=word.substr(1);
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(rec(board, nx, ny, w)) return true ;
        }
        board[x][y]=c;
        
        return false;
    }  
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                string s="";
                s+=board[i][j];
                if(!check(word, s)) continue;
                char c=board[i][j];
                board[i][j]='.';
                if(rec(board, i, j, word, s)) return true;
                board[i][j]=c;
            }
        }
        return false;
    }
    
    bool check(string word, string target){
        if(word.substr(0, target.size())==target) return true;
        else return false;
    }
    
    bool rec(vector<vector<char>>& board, int x, int y, string word, string cur){
        int dx[4]={1, 0, -1, 0};
        int dy[4]={0, 1, 0, -1};
        cout << cur << ' '  << '\n';
        if(cur.size()==word.size()) return true;
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=board.size() || nx<0 || ny>=board[0].size() || ny<0) continue;
            if(!check(word, cur+board[nx][ny])) continue;
            
            char c=board[nx][ny];
            board[nx][ny]='.';
            if(rec(board, nx, ny, word, cur+c)) return true ;
            board[nx][ny]=c;
        }
        return false;
    }  
};