/*
    Difference : Iteration vs function call
    better solution only recurs when there is palindrome
    Also significant saving of space by doing dfs



*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        partition(s, 0, path, result);//dfs calls
        return result;
    }
private: 
    //DFS steps
    void partition(string& s, int start, vector<string>& path, vector<vector<string>>& result) {
        int n = s.length();
        if (start == n) {
            result.push_back(path);
        } else {
            for (int i = start; i < n; i++) {
                if (isPalindrome(s, start, i)) {
                    path.push_back(s.substr(start, i - start + 1));
                    partition(s, i + 1, path, result);
                    path.pop_back();
                }
            }
        }
    }
    //helper function to safe check whether a substr is palindrome or not
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};


class Solution { // inefficient
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        backtrack(s, result, {}, 0, 1);
        return result;
    }
    
    bool isPal(string &s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]) return false;
        }
        return true;
    }
    
    void backtrack(string &s, vector<vector<string> > &result, vector<string> validPartition, int start, int len){
        string sub=s.substr(start, len);

        if(start+len==s.size()){
            if(!isPal(sub)) return;
            validPartition.push_back(sub);
            result.push_back(validPartition);
            return;
        }
        
        backtrack(s, result, validPartition, start, len+1);

        if(isPal(sub)){
            validPartition.push_back(sub);
            backtrack(s, result, validPartition, start+len, 1);
        }
        
        return;
        
    }
};


