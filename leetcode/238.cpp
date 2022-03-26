class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       
        int length=nums.size();
        vector<int> result;
        vector<int> prefix(length, 1);
        vector<int> suffix(length, 1);
        
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]*nums[i-1];
            suffix[i]=suffix[i-1]*nums[length-i];
        }
        
        for(int i=0;i<length;i++){
            result.push_back(prefix[i]*suffix[length-i-1]);
        }
        
        
        return result;
    }
};