class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      unordered_map<int, int> m;
      int ans=0;
      for(int i=0;i<nums.size();i++ ){
        int current=nums[i];
        if(m[current]>=1){
          m[current]--;
          ans++;
        }else{
          m[k-current]++;
        }
      }
      return ans;
    }
};