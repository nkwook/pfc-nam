class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string empty="";
        for(int i=0;i<n;i++) empty+='.';
        vector<string> init(n, empty);
        vector<bool> columnUsed(n, false);
        vector<bool> diagLeftUsed(2*n, false);
        vector<bool> diagRightUsed(2*n, false);
        solve(result, init, 0, n, columnUsed, diagLeftUsed, diagRightUsed);
        return result;
    }
    
    void solve(vector<vector<string>> &result, vector<string> qmap, int x, int n, 
               vector<bool> &c, vector<bool> &dl, vector<bool> &dr){
        if(x==n){
            result.push_back(qmap);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(c[i] || dl[i+x] || dr[n-(i-x)]) continue;
            c[i]=true;
            dl[i+x]=true;
            dr[n-(i-x)]=true;
            qmap[x][i]='Q';
            solve(result, qmap, x+1,n,  c, dl, dr);
            qmap[x][i]='.';
            c[i]=false;
            dl[i+x]=false;
            dr[n-(i-x)]=false;
        }
        return;
    }
    
};