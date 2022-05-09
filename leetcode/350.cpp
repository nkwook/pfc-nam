class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        
        vector<int> result;
        for(int i: nums1) m1[i]++;
        for(int i:nums2) m2[i]++;
        
        for(auto it=m1.begin(); it!=m1.end(); it++){
            if(m2.find(it->first)!=m2.end()){
                int iter=min(it->second, m2[it->first]);
                while(iter--){
                    result.push_back(it->first);
                }
            }
        }
        return result;
    }
};