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
    int moves;
    int solve(TreeNode*node){//keeps track of additional candies 
        if(node==nullptr) return 0;
        int r1=solve(node->left);
        int r2=solve(node->right);
        int res=((r1+r2)+(node->val))-1;//total candies - 1 that i must keep
        moves+=abs(res);//distance just ads up 
        return res;
    }
    int distributeCoins(TreeNode* root) {
        moves=0;
        solve(root);
        return moves;
    }
};