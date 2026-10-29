typedef long long ll;
class Solution {
public:
    const ll MOD=1e9+7;
    int fastPow_iterative(int a,int x){
        ll res=1,curr=a;
        for(int i=0;i<32;i++){
            if((x>>i)&1) res=(res*curr)%MOD;
            curr=(curr*curr)%MOD;
        }
        return static_cast<int>(res);
    }
    int dfs(int i,int par,const vector<vector<int>>&adj){
        int maxDepth=0;//here depth is using edges not nodes
        for(auto&j:adj[i]){
            if(j==par) continue;
            maxDepth=max(maxDepth,dfs(j,i,adj)+1);
        }
        return maxDepth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        for(auto&e:edges){
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        int max_depth=dfs(0,-1,adj);//here depth is using edges not nodes
        return fastPow_iterative(2,max_depth-1);//assumes max depth >=1
    }
};