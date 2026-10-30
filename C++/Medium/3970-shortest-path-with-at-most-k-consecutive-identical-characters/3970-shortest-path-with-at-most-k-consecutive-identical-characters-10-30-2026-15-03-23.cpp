typedef array<int,3> a;
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto&e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        priority_queue<a,vector<a>,greater<a>>pq;
        vector<vector<int>>dist(n+1,vector<int>(k+1,INT_MAX));
        pq.push({0,0,1});
        while(!pq.empty()){
            auto[c,nd,f]=pq.top();pq.pop();
            if(nd==n-1) return c;
            for(auto&[z,w]:adj[nd]){
                auto f_=(labels[z]==labels[nd])?f+1:1;
                if(f_>k) continue;
                auto c_=c+w; 
                if(c_>=dist[z][f_]) continue;
                pq.push({c_,z,f_});
                dist[z][f_]=c_;
            }
        }
        return -1;
    }
};