class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto&e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>pq;//{cost,time,node}
        pq.push({passingFees[0],0,0});
        vector<int>minTime(n,maxTime+1);
        while(!pq.empty()){
            auto [cost,time,node]=pq.top();
            pq.pop();
            if(time>=minTime[node]) continue;
            minTime[node]=time;
            if(node==n-1) return cost;
            for(auto&[neigh,delta]:adj[node]){
                if(time+delta<=maxTime){
                    pq.push({cost+passingFees[neigh],time+delta,neigh});
                }
            }
        }
        return -1;
    }
};