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

/* It was tough...
*   It is good idea to make reference parameter d. so we can save space a lot
    가능한 경우의 수: 해당지점에서 최대 길이가 생기거나, 해당 지점의 높이가 이용됨. 
    그래서 최대 길이가 어딘지 모르니까 
    본래 pair 배열 선언해서 최댓값 찾았던것 같은데, 생각해보니 안 그래도 됨.
    그리고 리턴값 이용해서 ld, rd 구하게 하는거 크 깔끔하다 다시 보면 풀 수 있을까...
*
*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // vector<pair<int, int>> diameter(10001, {0, 0});
        int d=0;
        dfs(root, d);
        return d;
    }
    
    int dfs(TreeNode* node, int& d){
        if(node==nullptr) return 0;
        
        int ld=dfs(node->left, d);
        int rd=dfs(node->right, d);
                

        if(d < ld+rd){
            d=ld+rd;
        }
        return max(ld, rd)+1;

    }
};