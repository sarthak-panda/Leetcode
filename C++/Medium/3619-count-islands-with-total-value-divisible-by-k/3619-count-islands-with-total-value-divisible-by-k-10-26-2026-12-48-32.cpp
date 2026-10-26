typedef long long ll;
int m; const vector<vector<int>>*grid_g;
inline int get_row_major(int i,int j){
    return j+i*m;
}
inline int get_value(int row_major){
    int j=row_major%m,i=row_major/m;
    return (*grid_g)[i][j];
}
struct DSU{
    int n;
    vector<int>parent,rank;
    vector<ll>sum_compo;
    DSU(int n):n(n),parent(n),rank(n,0),sum_compo(n,0){
        iota(parent.begin(),parent.end(),0);
        for(int i=0;i<n;i++) sum_compo[i]=get_value(i);
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
        sum_compo[x]+=sum_compo[y];
        if(rank[x]==rank[y]) rank[x]++;
        return true;
    }
};
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int nl=grid.size(),ml=grid[0].size();
        m=ml,grid_g=&grid;
        DSU d(nl*ml);
        for(int j=1;j<ml;j++){ 
            if(grid[0][j-1]!=0 && grid[0][j]!=0){ 
                d.unite(get_row_major(0,j-1),get_row_major(0,j));
            }
        }
        for(int i=1;i<nl;i++){
            if(grid[i][0]!=0 && grid[i-1][0]!=0){ 
                d.unite(get_row_major(i,0),get_row_major(i-1,0));
            }
            for(int j=1;j<ml;j++){ 
                if(grid[i][j-1]!=0 && grid[i][j]!=0){ 
                    d.unite(get_row_major(i,j-1),get_row_major(i,j));
                }
                if(grid[i][j]!=0 && grid[i-1][j]!=0){ 
                    d.unite(get_row_major(i,j),get_row_major(i-1,j));
                }
            }
        }
        int num_island=0;
        for(int z=0;z<nl*ml;z++){
            if(get_value(z)!=0 && d.find(z)==z){
                if(d.sum_compo[z]%k==0) num_island++;
            }
        }
        return num_island;
    }
};