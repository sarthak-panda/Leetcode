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
        vector<bool>res; res.reserve(queries.size()+1);
        for(auto&q:queries){
            int u=q[0],v=q[1];
            auto it_u=upper_bound(new_compo_beginnings.begin(),new_compo_beginnings.end(),u);
            auto it_v=upper_bound(new_compo_beginnings.begin(),new_compo_beginnings.end(),v);
            int compo_id_u=distance(new_compo_beginnings.begin(),it_u);
            int compo_id_v=distance(new_compo_beginnings.begin(),it_v);
            res.push_back((compo_id_u==compo_id_v));
        }
        return res;
    }
};