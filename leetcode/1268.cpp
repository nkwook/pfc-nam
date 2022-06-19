class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        vector<vector<string> > result(searchWord.size()+1, vector<string>());
        
        for(string s:products){
            if(s[0]!=searchWord[0]) continue;
            result[0].push_back(s);
        }
        
        for(int i=1;i<=searchWord.size();i++){
            for(string s: result[i-1]){
                if(s[i]!=searchWord[i]) continue;
                result[i].push_back(s);
            }
            
            int sz=result[i-1].size();
            for(int j=0;j<sz-3;j++){
                result[i-1].pop_back();
            }
        }
        result.pop_back();
        
        
        return result;
    }
};