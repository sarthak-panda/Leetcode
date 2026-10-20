class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&e:flights) adj[e[0]].push_back({e[1],e[2]});
        //bfs approach
        vector<int>dist(n,INT_MAX);
        dist[src]=0;

        queue<pair<int,int>>q; q.push({src,0});
        int level=0;
        while(!q.empty() && level<k+1){//k=0, means stops, 1 shot hit, so 1 step alowed
            int num_cands=q.size();
            while(num_cands--){
                auto[curr,d]=q.front(); q.pop();
                for(auto&[neigh,rd]:adj[curr]){
                    if(d+rd<dist[neigh]){
                        dist[neigh]=d+rd;
                        q.push({neigh,dist[neigh]});
                    }
                }
            }
            level++;
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];
    }
};