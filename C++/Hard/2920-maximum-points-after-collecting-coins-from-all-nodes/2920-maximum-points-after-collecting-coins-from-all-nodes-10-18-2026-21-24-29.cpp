class Solution {
public:
    int t[100001][14];
    int solve(int i,int par,int pow,const int& k,const vector<vector<int>>&adj,const vector<int>& coins){
        if(pow>=14) return 0;
        if(t[i][pow]!=-1) return t[i][pow];
        int case1=(coins[i]>>pow)-k;
        int case2=(coins[i]>>(pow+1));
        for(auto&j:adj[i]){
            if(j==par) continue;
            case1+=solve(j,i,pow,k,adj,coins);
            case2+=solve(j,i,pow+1,k,adj,coins);
        }
        return t[i][pow]=max(case1,case2);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        memset(t,-1,sizeof(t));
        int n=edges.size()+1;
        vector<vector<int>>adj(n);
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return solve(0,-1,0,k,adj,coins);
    }
};