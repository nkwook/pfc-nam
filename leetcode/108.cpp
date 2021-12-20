#include <iostream>
using namespace std;
#include <vector>

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {

        if (nums.size() == 1)
            return new TreeNode(nums[0]);
        else if (nums.size() == 2)
            return new TreeNode(nums[0], nullptr, new TreeNode(nums[1]));
        else if (nums.size() == 3)
            return new TreeNode(nums[1], new TreeNode(nums[0]), new TreeNode(nums[2]));

        int parentIndex = nums.size() / 2 ;
        vector<int> leftNums{nums.begin() , 
            nums.begin() + parentIndex };
        vector<int> rightNums={nums.begin() + parentIndex+1
            , nums.end()};
        cout << nums[parentIndex] << '\n';
        for(int i:leftNums) 
            cout << i << " ";
        cout << '\n';
        for(int i:rightNums) 
            cout << i << " ";
        return new TreeNode(nums[parentIndex], 
            sortedArrayToBST(leftNums),
            sortedArrayToBST(rightNums));
    }
};

// int main()
// {
//     Solution s;
//     vector<int> v{-10, -3, 0, 5, 9};
//     TreeNode* r=s.sortedArrayToBST(v);
//     // for(auto rr: r){}
//         // cout << rr <<" ";
// }