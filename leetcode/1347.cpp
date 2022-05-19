class Solution {
public:
    int minSteps(string s, string t) {
      unordered_map<char, int> m;

      for( char c: s){
        m[c]++;
      }

      for(char c: t){
        m[c]--;
      }
      int result=0;
      for(auto it=m.begin();it!=m.end();it++){
        result+=abs(it->second);
      }
      return result/2;
      
    }
};