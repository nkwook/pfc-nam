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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > result;
        if(root==nullptr){ return result;}
        
        queue<pair<TreeNode*, int>> Q;
        
        Q.push({root, 0});
        int prevH=0;
        vector<int> v;
        while(!Q.empty()){
            TreeNode* t=Q.front().first;
            int h=Q.front().second;
            Q.pop();
            // cout << t->val << ' ' << h <<'\n';
            if(t->left!=nullptr){
                Q.push({t->left, h+1});
            }
            if(t->right != nullptr){
                Q.push({t->right, h+1});
            }
            
            if(h!=prevH){
                prevH=h;
                result.push_back(v);
                v.clear();
            }
            
            v.push_back(t->val);
            
        }
        result.push_back(v);
        return result;
    }
};