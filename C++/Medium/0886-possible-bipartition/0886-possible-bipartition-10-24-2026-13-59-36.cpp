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
        DSU d(2*n+1);
        for(auto&e:dislikes){
            int u=e[0],v=e[1];
            if(d.find(u)==d.find(v)) return false;
            d.unite(u,v+n); d.unite(v,u+n);
        }
        return true;
    }
};