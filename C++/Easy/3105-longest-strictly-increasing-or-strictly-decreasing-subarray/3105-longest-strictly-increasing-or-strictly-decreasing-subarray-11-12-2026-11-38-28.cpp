class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int best=1,up=1,down=1,n=nums.size();
        for(int i=1;i<n;i++){
            up=(nums[i-1]<nums[i])?(up+1):1;
            down=(nums[i-1]>nums[i])?(down+1):1;
            best=max({best,up,down});
        }
        return best;
    }
};