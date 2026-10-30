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

typedef long long ll;
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>res;
        while(!q.empty()){
            int N=q.size(),N_ACT=N;
            ll S=0;
            while(N--){
                auto curr=q.front();q.pop();
                S+=curr->val;
                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);
            }
            double r=((S*1.0)/N_ACT);
            res.push_back(r);
        }
        return res;
    }
};