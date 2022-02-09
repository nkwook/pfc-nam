class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        return bsearch(nums, 0, nums.size()-1);
    }
    
    bool check(vector<int> &nums, int idx){
        if(idx==0) return nums[idx]>nums[idx+1];
        else if(idx==nums.size()-1) return nums[idx]>nums[idx-1];
        else return (nums[idx]>nums[idx-1] && nums[idx]>nums[idx+1]);
    }
    
    int bsearch(vector<int> &nums, int start, int end){
        if(end-start<=1){
            if(check(nums, end)) return end;
            else return start;
        }
        int mid=(start+end)/2;
        if(check(nums, mid)) return mid;
        else if(nums[mid]<nums[mid-1]) return bsearch(nums, start, mid-1);
        else return bsearch(nums, mid+1, end);
    }
};