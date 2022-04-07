class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int, int> m;
        
        int result=0;
        m[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){            
            sum+=nums[i];
            result+=m[sum-k];
            m[sum]++;    
        }
        
        return result;
    }
};

class Solution { // O(n), also we can use only sum....
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        vector<int> prefixSum(1, 0);
        unordered_map<int, int> m;
        int pSum=0;
        for(int i=0;i<nums.size();i++){
            pSum+=nums[i];
            prefixSum.push_back(pSum);
        }
        
        int result=0;
        m[0]=1;
        for(int i=1;i<=nums.size();i++){            
            result+=m[prefixSum[i]-k];
            m[prefixSum[i]]++;    
        }
        
        return result;
    }
};


//brute force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        vector<int> prefixSum(1, 0);
        int pSum=0;
        for(int i=0;i<nums.size();i++){
            pSum+=nums[i];
            prefixSum.push_back(pSum);
        }
        
        
        for(int i=1;i<=nums.size();i++){            
            for(int j=i;j<=nums.size();j++){
                if(prefixSum[j]-prefixSum[j-i] ==k) cnt++;
            }
        }
        
        return cnt;
    }
};