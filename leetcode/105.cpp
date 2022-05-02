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
// constructing이라서 범위 처음끝으로 잡을 엄두를 못 냈음.... 
class Solution { //better to use map..
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        unordered_map<int, int> inorderMap;
        for(int i=0;i<inorder.size();i++){
            inorderMap[inorder[i]]=i;
        }
        
        return rec(preorder, inorder, idx, 0, inorder.size()-1, inorderMap);
            
               
    }
    TreeNode* rec(vector<int>& preorder, vector<int>& inorder, int &index, int start, int end, unordered_map<int, int>& inorderMap){
        if(start>end) return nullptr;
        
        int inorderIndex=inorderMap[preorder[index]];
        cout << index << ' ' << inorderIndex << '\n';
        
        TreeNode* node=new TreeNode(preorder[index]);
        
        index++;
        node->left=rec(preorder, inorder, index, start, inorderIndex-1, inorderMap);
        node->right=rec(preorder, inorder, index, inorderIndex+1, end, inorderMap);
            
        return  node;
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        
        return rec(preorder, inorder, idx, 0, inorder.size()-1);
            
               
    }
    TreeNode* rec(vector<int>& preorder, vector<int>& inorder, int &index, int start, int end){
        if(start>end) return nullptr;
        
        int inorderIndex=-1;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==preorder[index]){
                inorderIndex=i;
                break;
            }
        }
        
        TreeNode* node=new TreeNode(preorder[index]);
        
        index++;
        node->left=rec(preorder, inorder, index, start, inorderIndex-1);
        node->right=rec(preorder, inorder, index, inorderIndex+1, end);
            
        return  node;
    }
        
};