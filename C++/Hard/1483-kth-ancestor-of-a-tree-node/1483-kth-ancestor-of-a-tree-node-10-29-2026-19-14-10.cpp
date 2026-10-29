const int MAXN=50005;
const int LOG_H=20;//we can handle ~10^6 nodes with this depth
int up[MAXN][LOG_H+1];

void dfs(int i,int par,vector<vector<int>>&adj){
    up[i][0]=par;
    for(int j=1;j<=LOG_H;j++){
        up[i][j]=up[up[i][j-1]][j-1];
    }
    for(auto&j:adj[i]){
        if(j==par) continue;
        dfs(j,i,adj);
    }
}

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        memset(up,0,sizeof(up));
        //we will convert it to 1 based indexing 0 will be dummy
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n;i++){
            adj[parent[i]+1].push_back(i+1);//-1 parent points to dummy
        }
        dfs(1,0,adj);//0th node in orig is 1th node here
    }
    
    int getKthAncestor(int node, int k) {
        int curr=node+1;
        for(int z=min(31,LOG_H);z>=0;z--){
            if((k>>z)&1){
                curr=up[curr][z];
            }
        }
        return curr-1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */