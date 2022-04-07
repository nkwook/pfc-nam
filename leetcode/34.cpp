class Solution { // we dont need highsearch: lowsearch(target+1) works same
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1, -1};
        }
        else if(nums.size()==1){
            if(nums[0]==target){
                return {0, 0};
            }else{
                return {-1, -1};
            }
        }
       return {lowSearch(nums, target, 0, nums.size()-1), highSearch(nums, target, 0, nums.size()-1)}; 
    }

    int lowSearch(vector<int> & nums, int target, int start, int end){
      if(start+1==end){
        if(nums[start]==target) return start;
        else if(nums[start]!=target && nums[end]==target) return end;
        else return -1;
      }
      
      int mid=(start+end+1)/2;

      if(nums[mid] < target) return lowSearch(nums, target, mid, end);
      else return lowSearch(nums, target, start, mid);
      
    }

      int highSearch(vector<int> & nums, int target, int start, int end){    
      if(start+1==end){
        if(nums[end]==target) return end;
        else if(nums[start]==target && nums[end]!=target) return start;
        else return -1;
      }
      
      int mid=(start+end+1)/2;

      if(nums[mid] <= target) return highSearch(nums, target, mid, end);
      else return highSearch(nums, target, start, mid);
      
    }

};