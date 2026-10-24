struct DSU{
    int n;
    vector<int> parent,rank;
    DSU(int n):n(n),parent(n),rank(n,0){
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        if(x!=parent[x]) parent[x]=find(parent[x]);
        return parent[x];
    }
    bool unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y) return false;
        if(rank[x]<rank[y]) swap(x,y);
        parent[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
        return true;
    }
};
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto&e:dislikes){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        //idea enemies of common guy are friends among themselves
        //so we should connect them
        DSU d(n+1);
        for(int i=1;i<=n;i++){
            if(adj[i].empty()) continue;
            // 1. Check for contradiction: is 'i' friends with any of its enemies?
            for(int enemy:adj[i]){
                if(d.find(i)==d.find(enemy)) return false;
            }
            // 2. Unite all enemies together (we don't care if unite returns false here)
            // here unite returning false means "these two enemies of 'i' were already grouped together as 
            //friends earlier." This is perfectly fine! It is not a contradiction. Redundant friend 
            //connection is not a failure.
            for(int j=1;j<adj[i].size();j++){
                d.unite(adj[i][j-1],adj[i][j]);
            }
        }
        return true;
    }
};