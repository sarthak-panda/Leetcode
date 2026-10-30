class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>components(n,-1);
        int compoId=0;
        components[0]=compoId;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                compoId++;
            }
            components[i]=compoId;
        }
        vector<bool>result(queries.size()); int q_idx=0;
        for(auto&q:queries){
            int u=q[0],v=q[1];
            int compo_id_u=components[u],compo_id_v=components[v];
            result[q_idx]=((compo_id_u==compo_id_v)); q_idx++;
        }
        return result;
    }
};