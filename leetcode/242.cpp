class Solution {
public:
    // 112~
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        
        if(s.length() != t.length()) return false;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
            m[t[i]]--;
        }
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second!=0) return false;
        }
        return true;
    }
};