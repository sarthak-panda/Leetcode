typedef pair<int,int> pii;
typedef pair<int,pii> ppi;
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        priority_queue<ppi,vector<ppi>,greater<ppi>>minHeap;//cost,node,remaing discounts
        vector<vector<pii>>adj(n);//nodeid,cost
        for(auto&e:highways){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<vector<int>> minCostTillNow(n,vector<int>(discounts+1,INT_MAX));//node,discount
        minHeap.push({0,{0,discounts}});
        minCostTillNow[0][discounts]=0;
        while(!minHeap.empty()){
            auto[c,nrd]=minHeap.top();auto&[node,rd]=nrd;
            minHeap.pop();
            if(c>minCostTillNow[node][rd]) continue;
            minCostTillNow[node][rd]=c;
            if(node==n-1) return c;
            for(auto&[neigh,w]:adj[node]){
                //case-1, no discount used here
                if(c+w<minCostTillNow[neigh][rd]){
                    minHeap.push({c+w,{neigh,rd}});
                    minCostTillNow[neigh][rd]=c+w;
                }
                //case-2 use discounts
                if(rd>0 && c+(w/2)<minCostTillNow[neigh][rd-1]){
                    minHeap.push({c+(w/2),{neigh,rd-1}});
                    minCostTillNow[neigh][rd-1]=c+(w/2);
                }
            }
        }
        return -1;
    }
};