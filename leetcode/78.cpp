class Solution { //O(N*2^N)
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> v;
        rec(result, v, 0, nums);
        return result;
    }
    
    void rec(vector<vector<int>> &r, vector<int> v, int cnt, vector<int>& nums){
        if(cnt==nums.size()){
            r.push_back(v);
            return;
        }
        
        rec(r, v, cnt+1, nums);
        v.push_back(nums[cnt]);
        rec(r, v, cnt+1, nums);
        return;
        
    }
};