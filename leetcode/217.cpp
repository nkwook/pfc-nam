class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        
        for(int i:nums){
            if(m[i]) return true;
            m[i]=true;
        }
        return false;
    }
};