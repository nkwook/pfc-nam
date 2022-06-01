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
    vector<int> rightSideView(TreeNode* root) {
      vector<int> r(101, -111);
      inorder(root, r, 1);
      vector<int> result;
      for(int i:r){
        if(i==-111) break;
        result.push_back(i);
      }
      return result;
    }

    void inorder(TreeNode* root, vector<int> &result, int height){
      if(!root) return;
      inorder(root->left, result, height+1);
      
      result[height-1]=root->val;
      
      inorder(root->right, result, height+1);
      return;
    }

    

};