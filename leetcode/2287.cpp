class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int tsize=target.size();
        int result=0;
        //init
    
        unordered_map<char, int> tmap;
        unordered_map<char, int> smap;
        for(int i=0;i<tsize;i++){
            tmap[target[i]]++;
        }
        int cnt=0;
        for(int i=0;i<=s.size();i++){
            if(tmap.find(s[i])!=tmap.end()) {
                smap[s[i]]++;
            }
        }    
        if(tmap.size()!=smap.size()) return 0;
        
        
        while(true){
            
            for(auto it=smap.begin(); it!=smap.end();it++){
                smap[it->first]-=tmap[it->first];
                if(smap[it->first]<0) return result;
            }
            
            
            result++;
        }            
                        
    
        
        return result;
    }
};