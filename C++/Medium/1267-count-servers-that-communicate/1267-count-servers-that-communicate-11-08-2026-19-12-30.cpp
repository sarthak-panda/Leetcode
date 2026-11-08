int freq[501];
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),total_count=0,alone=0;
        memset(freq,0,sizeof(freq));
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                freq[i]+=1, freq[n+j]+=1, total_count++;
            }
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            if(grid[i][j]==1 && freq[i]==1 && freq[n+j]==1){
                alone++;
            }
        }
        return total_count-alone;
    }
};