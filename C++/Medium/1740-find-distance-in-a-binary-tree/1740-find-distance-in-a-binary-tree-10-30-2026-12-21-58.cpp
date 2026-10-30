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

const int MAXN=10004;
const int LOG_H=20;
int t[MAXN][LOG_H+1];
int depth[MAXN];

class Solution {
public:
    int timer_id;
    unordered_map<int,int>timer_mp;
    void dfs(TreeNode*curr,int par,int d){
        int x=timer_id++;
        timer_mp[curr->val]=x;
        t[x][0]=par;
        for(int i=1;i<=LOG_H;i++){
            t[x][i]=t[t[x][i-1]][i-1];
        }
        depth[x]=d;
        if(curr->left!=nullptr) dfs(curr->left,x,d+1);
        if(curr->right!=nullptr) dfs(curr->right,x,d+1);
    }
    int LCA(int u,int v){
        if(depth[v]>depth[u]) swap(u,v);
        //phase-1 same levelling
        int diff=depth[u]-depth[v];
        for(int i=LOG_H;i>=0;i--){
            if((diff>>i)&1){
                u=t[u][i];
            }
        }
        if(u==v) return u;//it was in ancestor line only
        //phase-2 jump same steps;
        for(int i=LOG_H;i>=0;i--){
            if(t[u][i]!=t[v][i]){
                u=t[u][i];
                v=t[v][i];
            }
        }
        return t[u][0];//last one jump
    }
    int findDistance(TreeNode* root, int p, int q) {
        timer_id=1;//since we use 0 as reserve dummy node, so we start floting ids from 1 and intial parent id is 0 (ie equivalent to -1 of root)
        timer_mp.clear();
        dfs(root,0,0);
        p=timer_mp[p],q=timer_mp[q];
        return depth[p]+depth[q]-2*depth[LCA(p,q)];
    }
};