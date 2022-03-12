class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        rec("(", n, 1, 0, result);
        return result;
    }
    
    void rec(string s, int n, int numOpen, int numClose, vector<string> &result){
        if(s.length()==2*n){
            result.push_back(s);
            return;
        }
        
        if(numOpen<n ){
            rec(s+'(', n, numOpen+1, numClose, result);
        }
        if(numOpen>0 && numClose<numOpen){
            rec(s+')', n, numOpen, numClose+1, result);        
        }
        return;
    }
    
    
};