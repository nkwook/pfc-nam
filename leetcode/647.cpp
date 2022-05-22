class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> v(s.size(), vector<bool>(s.size(), false));
        int result=0;

        for(int i=0;i<s.size();i++){
            v[i][1]=true;
            result++;
            if(i<s.size()-1 && s[i]==s[i+1]){
                v[i][2]=true;
                result++;
            } 
        }
        
        
        for(int i=3;i<=s.size();i++){
            for(int j=1;j<=s.size()-i+1;j++){
                if(!v[j][i-2]) continue;
                if(s[j-1]==s[j+i-2]){
                    result++;
                    v[j-1][i]=true;
                }

            }
        }
        return result;
        
    }
    

};