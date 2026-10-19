class Solution {
public:
    vector<int>res,num_nodes_subtree;
    int total_num_nodes;
    int solve(int i,int par,const vector<vector<int>>&adj){
        int res=0;
        num_nodes_subtree[i]=1;
        for(auto&j:adj[i]){
            if(j==par) continue;
            int r=solve(j,i,adj);
            res+=(r+num_nodes_subtree[j]);
            num_nodes_subtree[i]+=num_nodes_subtree[j];
        }
        return res;
    }
    void re_root(int root,int par,const vector<vector<int>>&adj){
        for(auto&child:adj[root]){
            if(child==par)continue;
            res[child]=res[root]+total_num_nodes-2*num_nodes_subtree[child];
            re_root(child,root,adj);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        res.assign(n,0); num_nodes_subtree.assign(n,0);
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        res[0]=solve(0,-1,adj);
        total_num_nodes=num_nodes_subtree[0];
        re_root(0,-1,adj);
        return res;
    }
};