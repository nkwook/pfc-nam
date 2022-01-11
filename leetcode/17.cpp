#include <vector>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
vector< vector<char> > letter= {{'a', 'b', 'c'}, {'d','e','f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}
	, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

vector< vector<bool> > vis;
for(char c: digits){
	int digit=c-'2';
	vector<bool > sub( letter[digit].size(), false);
	vis.push_back(sub);
}
vector<string> result;
rec(0, vis, "", result, digits, letter);

return result;
    }

    void rec(int pos, vector<vector<bool > > vis, string cur, vector<string> &result, string digits, vector<vector<char > > &letter){
	if(pos==digits.length()){
	result.push_back(cur);
	return;
}

for(int i=0;i<vis[pos].size(); i++){
	if(vis[pos][i]) continue;
	
	cur+=letter[digits[pos]-'2'][i];
	vis[pos][i]=true;
	rec(pos+1, vis, cur, result, digits, letter);
	cur.pop_back();

}
return;

}

	
};