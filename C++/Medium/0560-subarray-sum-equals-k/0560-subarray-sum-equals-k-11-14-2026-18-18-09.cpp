class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int result=0,cumm_sum=0,n=nums.size();
        mp[0]=1;
        for(int i=0;i<n;i++){
            cumm_sum+=nums[i];
            if(mp.count(cumm_sum-k)){
                result+=mp[cumm_sum-k];
            }
            mp[cumm_sum]+=1;
        }
        return result;
    }
};