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
    int solve(TreeNode* i,int par,int grand_par){
        if(i==nullptr) return 0;
        int r=((grand_par%2)==0)?i->val:0;
        r+=solve(i->left,i->val,par);
        r+=solve(i->right,i->val,par);
        return r;
    }
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root,-1,-1);
    }
};