class Solution {
    // string as a stack....
public:
    string removeKdigits(string num, int k) {
        string result;
    
        for (char c: num){
            while(k>0 && result.size() && result.back()>c){
                k--;
                result.pop_back();
            }
            if(!(c=='0' && result.empty())) result.push_back(c);
            
        }
        while(k-- && result.size()){
            result.pop_back();
        }
        
        if(result=="") result+='0';
                
        return result;
    }
};

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> S;
        string result;
    
        int cntk=k;
        for (char c: num){
            while(cntk>0 && !S.empty() && S.top()>c){
                cntk--;
                S.pop();
            }
            S.push(c);
            
        }
        while(S.size()!=(num.size()-k)) S.pop();
        
        while(!S.empty()){
            string temp="";
            temp+=S.top();
            result.insert(0, temp);
            S.pop();
        }
        
        int zeroCnt=0;
        for(char c: result){
            if(c!='0') break;    
            zeroCnt++;
        }
        
        result=result.substr(zeroCnt);
        if(result=="") result+='0';
                
        return result;
    }
};