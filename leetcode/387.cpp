class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> u;
        
        for(char c: s){
            if(u.find(c)==u.end()) u[c]=1;
            else u[c]=u[c]+1;
        }
        for(int i=0;i<s.length();i++){
            if(u[s[i]]==1) return i;
        }
        return -1;
    }
};