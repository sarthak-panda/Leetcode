class Solution {
public:
    static inline vector<pair<int,int>>dir={{0,-1},{-1,0},{1,0},{0,1}};
    inline bool check(int i,int j,const int&n,const int&m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    bool dfs(int i,int j,vector<bitset<100>>&visited,const int&n,const int&m,const vector<vector<int>>& grid){
        if(i==0||i==n-1||j==0||j==m-1) return false;
        visited[i][j]=1;
        bool res=true;
        for(auto&[di,dj]:dir){
            int ni=i+di,nj=j+dj;
            if(check(ni,nj,n,m) && !visited[ni][nj] && grid[ni][nj]==0){
                res&=dfs(ni,nj,visited,n,m,grid);
            }
        }
        return res;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),res=0;
        vector<bitset<100>>visited(n);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(grid[i][j]==0 && !visited[i][j]) res+=dfs(i,j,visited,n,m,grid);
        }
        return res;
    }
};