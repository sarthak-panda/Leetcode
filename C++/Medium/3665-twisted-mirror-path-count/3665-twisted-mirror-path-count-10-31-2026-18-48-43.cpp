int MOD=1e9+7;
int t[501][501][2];

class Solution {
public:
    int solve(int i,int j,char d,const int&n,const int&m,const vector<vector<int>>& grid){
        if(i==n-1 && j==m-1) return 1;
        if(t[i][j][d=='r']!=-1) return t[i][j][d=='r'];
        int r1=0,r2=0;
        if(grid[i][j]==0){
            if(i+1<n) r1=solve(i+1,j,'d',n,m,grid);
            if(j+1<m) r2=solve(i,j+1,'r',n,m,grid);
        }
        else{
            if(d=='d'){
                if(j+1<m) r2=solve(i,j+1,'r',n,m,grid);
            }else if(d=='r'){
                if(i+1<n) r1=solve(i+1,j,'d',n,m,grid);
            }
        }
        return t[i][j][d=='r']=(r1+r2)%MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        int n=grid.size(),m=grid[0].size();
        return solve(0,0,'d',n,m,grid);
    }
};