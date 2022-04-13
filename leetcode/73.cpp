class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      vector<int> r;
      vector<int> c;

      for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
          if(matrix[i][j]==0){
            r.push_back(i);
            c.push_back(j);
          }
        }
      }

      for(int i:r){
        for(int j=0;j<matrix[0].size();j++){
          matrix[i][j]=0;
        }
      }
      for(int i:c){
        for(int j=0;j<matrix.size();j++){
          matrix[j][i]=0;
        }
      }
      
    }
};