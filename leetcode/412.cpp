class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        
        string s="";
        for(int i=1;i<=n;i++){
            s="";
            if(i%3==0) s+="Fizz";
            if(i%5==0) s+="Buzz";
            if(s=="") s=to_string(i);
            
            result.push_back(s);
        }
        return result;
    }
};