class Solution {
public:
    int t[21][4005];
    int solve(int idx,int target,const int&n,const vector<int>& nums){
        if(idx==n) return (target==0);
        int eff_j=target+2001;
        if(t[idx][eff_j]!=-1) return t[idx][eff_j];
        int res=0;
        res+=solve(idx+1,target-nums[idx],n,nums);//+ taken
        res+=solve(idx+1,target+nums[idx],n,nums);//- taken
        return t[idx][eff_j]=res;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        return solve(0,target,nums.size(),nums);
    }
};