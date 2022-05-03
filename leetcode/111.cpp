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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int result=9999999;
        dfs(root, 1, result);
        return result;
    }

    int dfs(TreeNode* node, int depth, int &result){
        
        if(node==nullptr) return -1;
        
        int temp=0;
        if(depth>=result) return 0;
        temp+=dfs(node->left, depth+1, result);
        temp+=dfs(node->right, depth+1, result);
        if(temp==-2){
            result=min(result, depth);
        }
      

        return 0;
    }
};

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
class Solution { //better dfs
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);
            
        
        
        return 1+min(minDepth(root->left), minDepth(root->right));
    }

};


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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*, int>> Q;
        
        Q.push({root, 1});
        
        while(!Q.empty()){
            TreeNode* parent=Q.front().first;
            int depth=Q.front().second;
            Q.pop();
            if(!parent->left && !parent->right) return depth;
            
            if(parent->left) Q.push({parent->left, depth+1});
            if(parent->right) Q.push({parent->right, depth+1});
            
        }
        
        return -1;
        
    }

};