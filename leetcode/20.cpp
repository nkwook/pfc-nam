class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
      unordered_map<char, char> m; // maps are good!
      m[')']='(';
      m['}']='{';
      m[']']='[';


      for(char c: s){
        // s.push(c);
        if(c=='(' || c=='{' || c=='['){
          st.push(c);
        }else{
          if(st.empty()) return false;

          if(st.top()!=m[c]) return false;
          st.pop();
        }
      } 
      if(!st.empty()) return false;

      return true;
    }
};