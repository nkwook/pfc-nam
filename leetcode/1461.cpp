class Solution {
public:
    bool hasAllCodes(string s, int k) {        
        int ksize=1<<k;                  
        int kmask=ksize-1;
        vector<bool> v(ksize, false);
        
        int temp=0;
        if(s.size()<ksize) return false;
        for(int i=0;i<k;i++){
            temp*=2;
            temp+=s[i]-'0';
        }
        v[temp]=true;
        for(int j=k;j<s.size();j++){
            temp*=2;
            temp+=s[j]-'0';
            temp= temp&kmask;
            v[temp]=true;
        }
        
        for(int i=0;i<1<<k;i++){
            if(!v[i]) return false;
        }
        return true;
        
        
    }
};