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
    int dfs(TreeNode* node, int d, int p, int q,
            TreeNode*& ancestor, int& dp, int& dq, int& lcaDepth) {

        if (!node) return 0;

        int mask = 0;

        if (node->val == p) {
            dp = d;
            mask |= 1;
        }

        if (node->val == q) {
            dq = d;
            mask |= 2;
        }

        mask |= dfs(node->left, d + 1, p, q,
                    ancestor, dp, dq, lcaDepth);

        mask |= dfs(node->right, d + 1, p, q,
                    ancestor, dp, dq, lcaDepth);

        // First node whose subtree contains both p and q is the LCA.
        if (mask == 3 && ancestor == nullptr) {
            ancestor = node;
            lcaDepth = d;
        }

        return mask;
    }

    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* ancestor = nullptr;
        int dp = -1, dq = -1, lcaDepth = -1;

        dfs(root, 0, p, q, ancestor, dp, dq, lcaDepth);

        return dp + dq - 2 * lcaDepth;
    }
};