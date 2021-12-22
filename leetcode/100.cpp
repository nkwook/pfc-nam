// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {

// queue<TreeNode*> PQ;
// queue<TreeNode*> QQ;

// 	if(p->val == q->val){
// 		PQ.push(p);
// 		QQ.push(q);
// }else return false;

// while(!PQ.empty() && !QQ.empty()){
// 	frontPNode=PQ.front();
// 	frontQNode=QQ.front();
// 	PQ.pop();
// 	QQ.pop();

// 	if(!(frontPNode->left == nullptr && frontQNode->left ==nullptr)){
// 		if(frontPNode->left->val ==frontQNode->left->val ){
// 			PQ.push(frontPNode->left);
// 			QQ.push(frontQNode->left);
// }else{
// 	Return false;
// }
// }

// if(!(frontPNode->right == nullptr && frontQNode->right ==nullptr)){
// 		if(frontPNode->right->val ==frontQNode->right->val ){
// 			PQ.push(frontPNode->right);
// 			QQ.push(frontQNode->right);
// }else{
// 	Return false;
// }
// }

// Return true;
// }
      
//     }
// };
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // with recursion
        if(p==nullptr && q==nullptr) return true;
        else if(p==nullptr || q== nullptr) return false; 
        else if(p->val!=q->val) return false;
        cout << p->val << ' '<< q-> val << '\n';
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};