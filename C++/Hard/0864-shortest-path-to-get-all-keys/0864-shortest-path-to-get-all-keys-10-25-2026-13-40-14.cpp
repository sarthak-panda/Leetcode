class Solution {
public:
    inline static vector<pair<int,int>>dir={{0,-1},{-1,0},{1,0},{0,1}};
    int shortestPathAllKeys(vector<string>& grid) {
        int num_keys=0,sx,sy,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@') sx=i,sy=j;
                else if((grid[i][j]>='a') && (grid[i][j]<='z')) num_keys++;
            }
        }
        int endMask=(1<<num_keys)-1;
        queue<array<int,3>>que;
        vector<vector<vector<bool>>>visited(n,vector<vector<bool>>(m,vector<bool>(endMask+1,false)));
        que.push({sx,sy,0});
        visited[sx][sy][0]=true;
        int path=0;
        while(!que.empty()){
            int N=que.size();
            path++;
            while(N--){
                auto[i,j,c_mask]=que.front(); que.pop();
                for(auto&[di,dj]:dir){
                    int ni=i+di,nj=j+dj;
                    if(ni>=0 && ni<n && nj>=0 && nj<m){
                        if(grid[ni][nj]=='#') continue;
                        else if(grid[ni][nj]=='.'||grid[ni][nj]=='@'){
                            if(!visited[ni][nj][c_mask]){
                                visited[ni][nj][c_mask]=true;
                                que.push({ni,nj,c_mask});
                            }
                        }
                        else if((grid[ni][nj]>='A')&&(grid[ni][nj]<='Z')){
                            if(!visited[ni][nj][c_mask] && ((c_mask>>(grid[ni][nj]-'A'))&1)){
                                visited[ni][nj][c_mask]=true;
                                que.push({ni,nj,c_mask});
                            }
                        }
                        else if((grid[ni][nj]>='a')&&(grid[ni][nj]<='z')){
                            int n_mask=c_mask|(1<<(grid[ni][nj]-'a'));
                            if(!visited[ni][nj][n_mask]){
                                if(n_mask==endMask) return path;
                                visited[ni][nj][n_mask]=true;
                                que.push({ni,nj,n_mask});
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};