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
        queue<int> Q;
        vector<bool> vis(s.length(), false);
        unordered_set<string> dictSet;
        
            for(string w: wordDict){
                dictSet.insert(w);
            }
        
            for(string w: wordDict){
                if(dictSet.find(s.substr(0, w.length()))!=dictSet.end()){  
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
                    if(dictSet.find(s.substr(t, w.length()))!=dictSet.end()){
                        if(t+w.length()==s.length()) return true;
                        Q.push(t+w.length());
                    }
                }
                vis[t]=true;
                
            }
            return false;
        
    }
};