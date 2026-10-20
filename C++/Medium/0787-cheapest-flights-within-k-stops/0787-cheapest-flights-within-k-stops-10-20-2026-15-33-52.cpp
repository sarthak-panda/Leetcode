class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //using bellman ford, relax the edges just k+1 times and done
        //but a sepration of current and next needs to be done additionally
        //since we are tarhetting exact atmost k+1 steps and not atleat k+1
        vector<int>dist(n,INT_MAX),next_dist;
        dist[src]=0;
        for(int i=0;i<k+1;i++){
            next_dist=dist;
            for(auto&e:flights){
                if(dist[e[0]]!=INT_MAX && next_dist[e[1]]>(dist[e[0]]+e[2])) next_dist[e[1]]=dist[e[0]]+e[2];
            }
            dist=std::move(next_dist);
        }
        return (dist[dst]==INT_MAX)?-1:dist[dst];
        //next_dist[e[1]]>(dist[e[0]]+e[2]), to understand why it is not dist[e[1]]>(dist[e[0]]+e[2])
        //because say there are two edge from u to v then ome of 30 then other of 40, then
        //if 40 comes llater it will overwrite our better found 30,

        //Relaxing edges using dist[u], rather than next_dist[u], prevents newly discovered paths 
        // from being extended again during the same iteration.
    }
};