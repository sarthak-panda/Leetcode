class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>new_compo_beginnings;
        int l=0,r=0; new_compo_beginnings.push_back(l);
        while(r<n){
            int farthest_reachable=nums[r]+maxDiff;
            auto it=upper_bound(nums.begin()+r+1,nums.end(),farthest_reachable);
            int farthest_idx=distance(nums.begin(),it);
            if(r==farthest_idx-1) r++,l=r,new_compo_beginnings.push_back(l);//new compo
            else r=farthest_idx-1;
        }
        vector<int>compo_map(n);
        int total_compos=new_compo_beginnings.size();
        for(int compo_id=0;compo_id<total_compos;compo_id++){
            int beg_idx=new_compo_beginnings[compo_id];
            int end_idx=(compo_id+1<total_compos)?new_compo_beginnings[compo_id+1]-1:n-1;
            //both ends inclusive
            for(int idx=beg_idx;idx<=end_idx;idx++){
                compo_map[idx]=compo_id;
            }
        }
        vector<bool>res; res.reserve(queries.size()+1);
        for(auto&q:queries){
            int u=q[0],v=q[1];
            int compo_id_u=compo_map[u];
            int compo_id_v=compo_map[v];
            res.push_back((compo_id_u==compo_id_v));
        }
        return res;
    }
};