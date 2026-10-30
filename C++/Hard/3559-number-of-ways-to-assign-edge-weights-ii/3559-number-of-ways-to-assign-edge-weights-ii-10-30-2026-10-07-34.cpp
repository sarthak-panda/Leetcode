typedef long long ll;

const ll MOD=1e9+7;
const int MAXN=100005;
const int LOG_H=20;
int up[MAXN][LOG_H+1];

class Solution {
public:
    vector<int>dist;
    int fastPowIterative(int a,int x){
        ll res=1,curr=a;
        for(int i=0;i<32;i++){
            if((x>>i)&1) res=(res*curr)%MOD;
            curr=(curr*curr)%MOD;
        }
        return static_cast<int>(res);
    }
    void dfs(int i,int par,int distFromRoot,const vector<vector<int>>&adj){
        up[i][0]=par;
        for(int j=1;j<=LOG_H;j++){
            up[i][j]=up[up[i][j-1]][j-1];
        }
        dist[i]=distFromRoot;
        for(auto&j:adj[i]){
            if(j==par) continue;
            dfs(j,i,distFromRoot+1,adj);
        }
    }
    int LCA(int u,int v){
        if(dist[v]>dist[u]) swap(u,v);
        //phase-1 bring u to same level
        int diff_jump=dist[u]-dist[v];
        for(int j=LOG_H;j>=0;j--){
            if((diff_jump>>j)&1){
                u=up[u][j];
            }
        }
        if(u==v) return u;//ie they lied on same ancestor line
        //phase-2 jump same steps up together
        for(int j=LOG_H;j>=0;j--){
            if(up[u][j]!=up[v][j]){
                u=up[u][j];
                v=up[v][j];
            }
        }
        return up[u][0];//just one step up
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n=edges.size()+1;
        vector<vector<int>>adj(n+1);
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dist.assign(n+1,0);
        dfs(1,0,0,adj);
        vector<int>res;
        for(auto&q:queries){
            int u=q[0],v=q[1];
            if(u==v) res.push_back(0);
            else{
                int lca_uv=LCA(u,v);
                int dist_bw_uv=dist[u]+dist[v]-2*dist[lca_uv];
                res.push_back(fastPowIterative(2,dist_bw_uv-1));
            }
        }
        return res;
    }
};