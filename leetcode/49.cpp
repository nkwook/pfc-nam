class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> m;
      vector<vector<string>> result;
      for(string s: strs){
        string sorted=s;
        sort(sorted.begin(), sorted.end());
        m[sorted].push_back(s);
      }

      
      for(auto it=m.begin();it!=m.end();it++){
        result.push_back(it->second);
      }
      return result;
    }
};