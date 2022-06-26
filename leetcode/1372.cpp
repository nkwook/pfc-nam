/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
      int longest=0;
      dfs(root, true, 0, longest);
      return longest;
    }

    int dfs(TreeNode* root, bool isLeft, int cur, int& longest){
      if(!root) return cur-1;
      if(isLeft) {
        longest=max(longest, 
          max(dfs(root->left, false, cur+1, longest),
              dfs(root->right, true, 1, longest)));
      }else{
        longest=max(longest, 
         max( dfs(root->right, true, cur+1, longest),
          dfs(root->left, false, 1, longest))); 
      }
      return -1;
    }
    
};

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */


function longestZigZag(root: TreeNode | null): number {
    const left = helper(root, false,0);
    
    return left;
};

function helper(root, isLeft, length){
    if(root === null){
        return length - 1;
    }
    
    const left = helper(root.left, true, isLeft ? 1 : length + 1);
    
    const right = helper(root.right, false, isLeft ?  length + 1: 1);
    
    
    return Math.max(left, right);
    
}