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
    int maxDepth(TreeNode* root) {
        int maxD=0;
        rec(root, maxD, 1);
        return maxD;
    }
    
    void rec(TreeNode* node, int &maxD, int depth){
        if(!node) return;
        maxD=max(maxD, depth);
        
        rec(node->left, maxD, depth+1);
        rec(node->right, maxD, depth+1);
        return;
        
    }
    
};