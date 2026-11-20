class Solution {
public:
    int find_elm(int start_idx,int v,const vector<int>& nums){
        auto it=lower_bound(nums.begin()+start_idx,nums.end(),v);
        if(it==nums.end()||(*it!=v)) return -1;
        return distance(nums.begin(),it);
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),res=1;
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int inc=0;inc<=1;inc++){
                int curr_val=nums[idx]+inc,res=1;
                //direct find curr_val+1
                int j=find_elm(idx+1,curr_val+1,nums);
                if(j!=-1) res=max(res,1+dp[j][0]);
                //find curr_val and inc 1 there
                j=find_elm(idx+1,curr_val,nums);
                if(j!=-1) res=max(res,1+dp[j][1]);
                dp[idx][inc]=res;
            }
        }
        for(int i=0;i<n;i++){
            res=max(res,dp[i][0]);
            res=max(res,dp[i][1]);
        }
        return res;
    }
};