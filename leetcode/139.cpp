class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        queue<int> Q;
        bool vis[300]={};
        
            for(string w: wordDict){
                if(s.substr(0, w.length())==w){  
                    if(w.length()==s.length()) return true;
                   Q.push(w.length());
               }
            }     
            if(Q.empty()) return false;
            
            while(!Q.empty()){
                int t=Q.front();
                Q.pop();
                
                if(vis[t]) continue;
                for(string w: wordDict){
                    if(s.substr(t, w.length())==w){
                        if(t+w.length()==s.length()) return true;
                        Q.push(t+w.length());
                    }
                }
                vis[t]=true;
                
            }
            return false;
        
    }
};

// using hashset is faster
// comparing between == operator and find api
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1, false);
        unordered_set<string> dictSet;
        
        for(string w: wordDict){
            dictSet.insert(w);
        }

        for(int i=1;i<=s.size();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    if(dict.find(s.substr(j, i-j))!=dict.end()){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }        
        
        return dp[s.size()];
        
    }
};