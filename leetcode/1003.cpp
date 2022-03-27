class Solution {
public:
    bool isValid(string s) {
      stack<char> stk;
      char prev='c';
      for(int i=0;i<s.size();i++){
          char cur=s[i];
      
        if(cur=='a'){
            stk.push('c');
            stk.push('b');          
        }else if(cur=='b'){
            if(stk.empty()) return false;

           if(stk.top()=='b'){
              stk.pop();
            }else{
              return false;
            }
          
        }else if(cur=='c') {
            if(stk.empty()) return false;
            if(stk.top()=='c'){
              stk.pop();
            }else{
              return false;
            }
          }      
    }
        if(stk.empty()){
        return true;      
      }
        return false;
      
}};