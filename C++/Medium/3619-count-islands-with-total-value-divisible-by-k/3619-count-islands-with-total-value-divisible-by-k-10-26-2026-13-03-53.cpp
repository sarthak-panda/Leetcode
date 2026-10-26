struct DSU{
    vector<int>parent,rank,sum_compo;
    // Removed sum_compo initialization from constructor
    DSU(int n):parent(n),rank(n,0),sum_compo(n,0){
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        if(x!=parent[x]) parent[x]=find(parent[x]);
        return parent[x];
    }
    // Pass k directly into unite
    bool unite(int x,int y, int k){
        x=find(x);y=find(y);
        if(x==y) return false;
        if(rank[x]<rank[y]) swap(x,y);
        parent[y]=x;
        sum_compo[x]=(sum_compo[x]+sum_compo[y])%k;
        if(rank[x]==rank[y]) rank[x]++;
        return true;
    }
};

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int nl = grid.size(), ml = grid[0].size();
        DSU d(nl * ml);
        
        // Inline helper replaces the global function
        auto get_row_major = [&](int i, int j) {
            return j + i * ml;
        };

        // 1. Initialize sum_compo directly (avoids slow / and % math)
        for(int i = 0; i < nl; i++) {
            for(int j = 0; j < ml; j++) {
                d.sum_compo[get_row_major(i, j)] = grid[i][j];
            }
        }

        // 2. Unite adjacent components
        for(int j = 1; j < ml; j++){ 
            if(grid[0][j-1] != 0 && grid[0][j] != 0){ 
                d.unite(get_row_major(0, j-1), get_row_major(0, j), k);
            }
        }
        for(int i = 1; i < nl; i++){
            if(grid[i][0] != 0 && grid[i-1][0] != 0){ 
                d.unite(get_row_major(i, 0), get_row_major(i-1, 0), k);
            }
            for(int j = 1; j < ml; j++){ 
                if(grid[i][j-1] != 0 && grid[i][j] != 0){ 
                    d.unite(get_row_major(i, j-1), get_row_major(i, j), k);
                }
                if(grid[i][j] != 0 && grid[i-1][j] != 0){ 
                    d.unite(get_row_major(i, j), get_row_major(i-1, j), k);
                }
            }
        }
        
        // 3. Count valid islands
        int num_island = 0;
        for(int i = 0; i < nl; i++){
            for(int j = 0; j < ml; j++){
                int z = get_row_major(i, j);
                if(grid[i][j] != 0 && d.find(z) == z){
                    if(d.sum_compo[z] % k == 0) num_island++;
                }
            }
        }
        return num_island;
    }
};