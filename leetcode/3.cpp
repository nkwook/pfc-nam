class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // more concise solution without cnt var
        // also we can use char -> num to vector index        
        unordered_map<char, int> m;
        int start=0;
        int max=0;

        for(int i=0;i<s.length();i++){
          if(m.find(s[i])!=m.end() && m[s[i]]>=start){
            start=m[s[i]]+1;
          }
          m[s[i]]=i;

          if(i-start+1>max){
            max=i-start+1;
          }
        }
        return max;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> m;
        int start=0;
        int max=0;
        int cnt=0;
        for(int i=0;i<s.length();i++){
          
          if(m.find(s[i])!=m.end() && m[s[i]]>=start){
            start=m[s[i]]+1;
            cnt=i-start;
          }
          m[s[i]]=i;
          cnt++;
          if(cnt>max){
            max=cnt;
          }
         
        }
        return max;
    }
};