class Solution {
public:
    typedef long long ll;
    vector<ll>coins;
    vector<vector<int>>maxi;
    vector<vector<int>>mini;
    static inline auto comp=[](const auto&a,const auto&b){
        return b<a;
    };
    int solve(int i, int par, const vector<vector<int>>&adj, const vector<int>&cost){
        int num_childs=adj[i].size()-(par!=-1);
        if(num_childs==0){
            if(cost[i]>0) maxi[i].push_back(cost[i]),coins[i]=1;
            if(cost[i]<0) mini[i].push_back(cost[i]),coins[i]=1;
            return 1;
        }
        priority_queue<int>mn_heap;
        priority_queue<int,vector<int>,decltype(comp)>mx_heap(comp);
        if(cost[i]>0) mx_heap.push(cost[i]);
        if(cost[i]<0) mn_heap.push(cost[i]);
        int total_sub_childs=0;
        for(auto&j:adj[i]){
            if(j==par) continue;
            total_sub_childs+=solve(j,i,adj,cost);
            for(auto&x:maxi[j]){
                mx_heap.push(x);
                if(mx_heap.size()>3) mx_heap.pop();
            }
            for(auto&x:mini[j]){
                mn_heap.push(x);
                if(mn_heap.size()>2) mn_heap.pop();
            }
        }
        ll pos_path=(mx_heap.size()<3)?0:1;
        ll neg_path=1;
        if(mn_heap.size()<2||mx_heap.empty()) neg_path=0;
        int max_pos=INT_MIN;
        while(!mx_heap.empty()){
            int curr=mx_heap.top();
            pos_path*=curr;
            maxi[i].push_back(curr);
            mx_heap.pop();
            max_pos=max(max_pos,curr);
        }
        if(max_pos!=INT_MIN) neg_path*=max_pos;
        while(!mn_heap.empty()){
            int curr=mn_heap.top();
            neg_path*=curr;
            mini[i].push_back(curr);
            mn_heap.pop();
        }
        if(total_sub_childs+1<3) coins[i]=1;
        else coins[i]=max({pos_path,neg_path,0LL});
        return total_sub_childs+1;
    }
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n=edges.size()+1;
        coins.assign(n,0); maxi.assign(n,{}); mini.assign(n,{});
        vector<vector<int>>adj(n);
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        solve(0,-1,adj,cost);
        return coins;
    }
};