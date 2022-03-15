class Solution { //from bigger index
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(k>=0){
            if(i==-1 || (j>=0 && nums1[i]<nums2[j])){
                nums1[k]=nums2[j];
                j--;
            }else{
                nums1[k]=nums1[i];
                i--;
            } 
            k--;
        }
        return;
    }
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;
        for(int i=0;i<m;i++){
            temp.push_back(nums1[i]);
        }
        
        bool condition=true;      
        int i=0;
        int j=0;
        int k=0;
        for(int k=0;k<m+n;k++){
           if(i==m || (j<n && temp[i]>nums2[j])){
                nums1[k]=nums2[j];
                j++;
            }else{
                nums1[k]=temp[i];
                i++;
            }
        }
        return;
    }
};

