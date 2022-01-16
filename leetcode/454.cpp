#include <algorithm>

#include <algorithm>

class Solution {
public:
    //N^2
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt=0;
        vector<int> v;
        unordered_map<int, int> m;
        int sz=nums1.size();
        for( int i=0;i<sz;i++) {
            for(int j=0;j<sz;j++){
                m[nums1[i]+nums2[j]]++;
            }
        }
        
        for( int i=0;i<sz;i++) {
            for(int j=0;j<sz;j++){
                cnt+=m[-(nums3[i]+nums4[j])];
            }
        }
        
            
        return cnt;
    }
    
    
};

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) { 
        //N^2lgN
        int cnt=0;
        vector<int> v1;
        vector<int> v2;
        
        for( int i=0;i<nums1.size();i++) {
            for(int j=0;j<nums2.size();j++){
                v1.push_back(nums1[i]+nums2[j]);
                v2.push_back(nums3[i]+nums4[j]);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for(int t: v1){
            cnt+=upper_bound(v2.begin(), v2.end(), -t)-lower_bound(v2.begin(), v2.end(), -t);
        }
        // cout << " fsd";
        return cnt;
    }
    
    // int lowerBound(int target, int start, int end, vector<int> &v2){
    //     if(end-start<1){
    //         return end;
    //     }
    //     int mid=(start+end)/2;
    //     if(v2[mid]>=target){
    //         return lowerBound(target, start, mid-1, v2);
    //     }else{
    //         return lowerBound(target, mid+1, end, v2);
    //     }
    // }
    // int upperBound(int target, int start, int end, vector<int> &v2){
    //     if(end-start<1){
    //         return end;
    //     }
    //     int mid=(start+end)/2;
    //     if(v2[mid]>target){
    //         return upperBound(target, start, mid-1, v2);
    //     }else{
    //         return upperBound(target, mid+1, end, v2);
    //     }
    // }
};