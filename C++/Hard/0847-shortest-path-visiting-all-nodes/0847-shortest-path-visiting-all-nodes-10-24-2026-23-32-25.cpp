class Solution {
public:
    typedef pair<int,int> p;
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1||n==0) return 0;
        int endMask=(1<<n)-1;
        queue<p>que; vector<vector<int>>visited(n,vector<int>(endMask));
        for(int i=0;i<n;i++){
            que.push({i,(1<<i)});
            visited[i][1<<i]=true;
        }
        int path=0;
        while(!que.empty()){
            int N=que.size();
            path++;
            while(N--){
                auto [curr,c_mask]=que.front();que.pop();
                for(int&neigh:graph[curr]){
                    int n_mask=c_mask|(1<<neigh);
                    if(n_mask==endMask) return path;
                    if(!visited[neigh][n_mask]){
                        que.push({neigh,n_mask});
                        visited[neigh][n_mask]=true;
                    }
                }
            }
        }
        return -1;
    }
};