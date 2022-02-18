class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      vector<int> result;
      stack<int> s;
      for(int i:digits){
        s.push(i);
      }
      int inc=1;
      while(!s.empty()){
        int top=s.top();
          s.pop();
        top+=inc;
        inc=0;
        if(top==10){
          inc++;
          top=0;
        }
        
        result.push_back(top);
      }
        if(inc){
            result.push_back(1);
        }
      reverse(result.begin(), result.end());
        return result;
    }
};