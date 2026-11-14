class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l=0,n=nums.size();
        long long res=0,curr_sum=0;
        set<int>s;
        for(int r=0;r<n;r++){
            while(s.count(nums[r])){
                s.erase(nums[l]);
                curr_sum-=nums[l];
                l++;
            }
            curr_sum+=nums[r];
            s.insert(nums[r]);
            if(r-l+1==k){
                res=max(res,curr_sum);
                s.erase(nums[l]);
                curr_sum-=nums[l];
                l++;
            }
        }
        return res;
    }
};