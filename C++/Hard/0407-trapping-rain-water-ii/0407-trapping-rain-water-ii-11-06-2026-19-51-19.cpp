static vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size(),m=heightMap[0].size();
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int j=0;j<m;j++){
            pq.push({heightMap[0][j],0,j});
            pq.push({heightMap[n-1][j],n-1,j});
            visited[0][j]=visited[n-1][j]=true;
        }
        for(int i=1;i<n-1;i++){
            pq.push({heightMap[i][0],i,0});
            pq.push({heightMap[i][m-1],i,m-1});
            visited[i][0]=visited[i][m-1]=true;
        }
        int ans=0;
        while(!pq.empty()){
            auto [h,i,j]=pq.top(); pq.pop();
            for(auto&[di,dj]:dir){
                int ni=i+di,nj=j+dj;
                if(ni<0||nj<0||ni>=n||nj>=m||visited[ni][nj]) continue;
                int water_accumulated_on_neigh=max(h-heightMap[ni][nj],0);
                ans+=water_accumulated_on_neigh;
                pq.push({heightMap[ni][nj]+water_accumulated_on_neigh,ni,nj});
                visited[ni][nj]=true;
            }
        }
        return ans;
    }
};