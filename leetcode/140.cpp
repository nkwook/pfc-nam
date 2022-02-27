class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        queue< pair<int, string> > Q;
        vector<string> result;
        
        
        for(string word: wordDict){
            if(s.substr(0, word.length())==word){
                Q.push({word.length(), word});
            }
        }
        
        while(!Q.empty()){
            int index=Q.front().first;
            string sentence=Q.front().second;
            Q.pop();
            if(index==s.length()){
                result.push_back(sentence);
                continue;
            }
            for(string word: wordDict){
                if(index+word.length()>s.length()) continue;
                string target=s.substr(index, word.length());
                if(target==word){
                    Q.push({index+word.length(), sentence+' '+word});
                }
            }
        }
        return result;
    }
};