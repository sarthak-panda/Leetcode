class Solution {
public:
    int t[1001][1024];
    int solve(int i,int j,int mask,const int&n,const int&m,const vector<vector<int>>& grid){
        if((i==n&&j==m-1)||(i==n-1&&j==m)) return mask;
        if(i==n||j==m) return INT_MAX;//u can return 1024
        if(t[j+i*m][mask]!=-1) return t[j+i*m][mask];
        int n_mask=mask^grid[i][j];
        int r1=solve(i+1,j,n_mask,n,m,grid);
        int r2=solve(i,j+1,n_mask,n,m,grid);
        return t[j+i*m][mask]=min(r1,r2);
    }
    int minCost(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        int n=grid.size(),m=grid[0].size();
        return solve(0,0,0,n,m,grid);
    }
};