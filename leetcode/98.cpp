
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev=nullptr;
        return inorder(root,  prev);
    }
    
    // without using queue, we can initialize prev struct, make it null init, 
    // and put as reference param, update!
    // also its important to decide execution of function and 
    // use conditionaly returning.... without multipling vars.
    bool inorder(TreeNode* node, TreeNode * &prev){
        if(node->left!=nullptr) {
            if(!inorder(node->left, prev)) return false;
        }
        
        if(prev!=nullptr && node->val <= prev->val) return false;
        prev=node;
        if(node->right!=nullptr)  {
           return inorder(node->right, prev);
        }
        return true;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        queue<int> Q;
        return inorder(root, root->val, Q);
    }
    
    bool inorder(TreeNode* node, int val, queue<int> &Q){
        bool leftSucc=true;
        bool rightSucc=true;
        if(node->left!=nullptr)  leftSucc= inorder(node->left, node->val, Q);
        if(!Q.empty()){
            int cmp=Q.front();
            Q.pop();
            if(cmp>=node->val) return false;
        }
        Q.push(node->val);
        cout << node->val <<'\n';

        if(node->right!=nullptr)  rightSucc= inorder(node->right, node->val, Q);
        
        return leftSucc && rightSucc;
    }
};