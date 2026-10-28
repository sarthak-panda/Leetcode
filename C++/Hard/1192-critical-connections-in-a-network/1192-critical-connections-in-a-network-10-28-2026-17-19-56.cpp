class Solution {
public:
    int timer=0;
    void dfs(int i,int par,vector<bool>&visited,vector<int>&tin,vector<int>&low,vector<vector<int>>&bridges,const vector<vector<int>>&adj){
        visited[i]=true;tin[i]=low[i]=++timer;
        for(auto&j:adj[i]){
            if(j==par) continue;
            if(visited[j]) low[i]=min(low[i],tin[j]);
            else{
                dfs(j,i,visited,tin,low,bridges,adj);
                low[i]=min(low[i],low[j]);
                if(low[j]>tin[i]){
                    bridges.push_back({i,j});
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        int m=connections.size();
        for(auto&e:connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool>visited(n,false);
        vector<int>tin(n,-1),low(n,-1);
        vector<vector<int>> bridges;
        timer=0;bridges.reserve(2*n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,-1,visited,tin,low,bridges,adj);
            }
        }
        return bridges;
    }
};