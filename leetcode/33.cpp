class Solution {
public:
    int search(vector<int>& nums, int target) {
        return bsearch(nums, 0, nums.size()-1, target);
    }
    
    int bsearch(vector<int>& nums, int start, int end, int target){
        int mid=(start+end)/2;
        if(end-start<=1){
            if(nums[end]==target){
                return end;
            }else if(nums[start]==target){
                return start;
            }else{
                return -1;
            }
        }
        else if(nums[mid]==target){
            return mid;
        }
        
        if(nums[start]<nums[mid]){
            if(target >=nums[start] && target < nums[mid]){
                return bsearch(nums, start, mid-1, target);
            }else{
                return bsearch(nums, mid, end, target);
            }
        }else{
            if(target >nums[mid] && target <= nums[end]){
                return bsearch(nums, mid+1, end, target);
            }else{
                return bsearch(nums, start, mid, target);
            }
                
            
        }
    }
};