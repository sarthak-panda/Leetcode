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
    void dfs(TreeNode* node,int d,const vector<int>&targs,vector<int>&res){
        if(node==nullptr) return;
        int x=node->val;
        if(x==targs[0]) res[0]=d;
        if(x==targs[1]) res[1]=d;
        if(x==targs[2]) res[2]=d;
        dfs(node->left,d+1,targs,res);
        dfs(node->right,d+1,targs,res);
    }
    TreeNode* lca(TreeNode* node,int p,int q){
        if(!node||(node->val==p)||(node->val==q)) return node;
        TreeNode* left=lca(node->left,p,q);
        TreeNode* right=lca(node->right,p,q);
        if(left&&right) return node;
        return left?left:right;
    }
    int findDistance(TreeNode* root, int p, int q) {
        int lca_pq=lca(root,p,q)->val;
        vector<int> targs={p,q,lca_pq},res(3,-1);
        dfs(root,0,targs,res);
        return res[0]+res[1]-2*res[2];
    }
};