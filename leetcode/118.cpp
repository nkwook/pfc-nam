class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> one(1, 1);
        result.push_back(one);
        if(numRows==1) {
            return result;
        }
        
        for(int i=1;i<numRows;i++){
            vector<int> v(i+1, 0);
            for(int j=0;j<i;j++){
                v[j]+=result[i-1][j];
                v[i-j]+=result[i-1][j];
            }

            result.push_back(v);
        }
        return result;
    }
};