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
    bool hasPathSum(TreeNode* root, int targetSum) {
        queue< pair<TreeNode*, int > > Q;
        if(root==nullptr) return false;
        
        Q.push({root, root->val});
        while(!Q.empty()){
            TreeNode* nd=Q.front().first;
            int psum=Q.front().second;
            Q.pop();
            bool noChild=true;
            if(nd->left!=nullptr){
                Q.push({nd->left, psum+nd->left->val});
                noChild=false;
            }
            if(nd->right!=nullptr){
                Q.push({nd->right, psum+nd->right->val});
                noChild=false;
            }
            if(psum==targetSum && noChild) return true;
            
            
        }
        return false;
    }
};