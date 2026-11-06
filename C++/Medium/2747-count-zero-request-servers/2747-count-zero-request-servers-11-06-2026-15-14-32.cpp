class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),[](const auto&a,const auto&b){
            return (a[1]<b[1])||(a[1]==b[1] && a[0]<b[0]);
        });
        vector<pair<int,int>>qs(queries.size());
        vector<int>res(queries.size());
        unordered_map<int,int>mp;
        for(int i=0;i<queries.size();i++) qs[i]={queries[i],i};
        sort(qs.begin(),qs.end());
        int l=0,r=0,N=queries.size();
        for(int i=0;i<N;i++){
            int query_start=qs[i].first-x;
            int query_end=qs[i].first;
            int ans_idx=qs[i].second;
            while(r<logs.size() && logs[r][1]<=query_end){
                mp[logs[r][0]]++;r++; 
            }
            while(l<logs.size() && logs[l][1]<query_start){
                mp[logs[l][0]]--;
                if(mp[logs[l][0]]==0) mp.erase(logs[l][0]);
                l++;
            }
            res[ans_idx]=n-mp.size();
        }
        return res;
    }
};