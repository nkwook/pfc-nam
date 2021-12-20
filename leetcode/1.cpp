#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

// 맵으로 계속 find하면 O(n)에 가능

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(), nums.end());
        int p=0; 
        int q=0;
        int sum=0;
        vector<int> v;

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                sum=nums[i]+nums[j];
                if(sum==target) {
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
                else if(sum>target) break;
            }
        }
        return v;


    }
};

int main(){
    Solution s;
    vector<int> n{2, 3, 5}
    int t=5;
    vector<int> r=s.twoSum(n, t);

    for(int i: r)
        cout << i << ' ';

}