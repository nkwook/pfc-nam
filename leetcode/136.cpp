class Solution { //SP(N)
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i:nums){
            if(m[i]) m[i]--;
            else m[i]++;
        }
        
        for(int i:nums){
            if(m[i]) return i;
        }
        return nums[0];

    }
};


class Solution { // using commutativity of XOR operation... SP(1)
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i:nums){
            result=result^i;
        }
        
        return result;

    }
};