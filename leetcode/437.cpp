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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int result=0;
        
        queue<pair<long, TreeNode*> > Q;
        unordered_map<TreeNode*, bool> M;
        Q.push({root->val, root});
        
        while(!Q.empty()){
            pair<long, TreeNode* > p=Q.front();
            Q.pop();
            long partialSum=p.first;
            TreeNode* node=p.second;
            if(partialSum==targetSum){
              result++;
            } 
            if(node->left){
                Q.push({partialSum+ node->left->val, node->left});
                if(M.find(node->left)==M.end()){
                    Q.push({node->left->val, node->left});
                    M[node->left]=true;
                }
            }
            if(node->right){          
                Q.push({partialSum+ node->right->val, node->right});
                if(M.find(node->right)==M.end()){
                    Q.push({node->right->val, node->right});
                    M[node->right]=true;
                }            
            }
        }
        return result;
    }
};

//beautiful solution.....
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> M;
        int result=0;
        M[0]++;
        dfs(root, 0, sum, M, result);
        return result;
    }
    
    void dfs(TreeNode* root, long cur, int sum, unordered_map<int, int> &M, int &result ){
        if(!root ) return ;
        cur+=root->val;
        if(M.find(cur-sum)!=M.end()){
            result+=M[cur-sum];
        }
        M[cur]++;
        dfs(root->left, cur, sum, M, result);
        dfs(root->right, cur, sum, M, result);
        M[cur]--;
        return;
    }
    
    

};