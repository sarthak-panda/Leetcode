class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        if(nums[0]!=0) return 0;
        int n=nums.size(),res=INT_MAX;
        for(int i=0;i<n;i++){
            if(i!=nums[i]) res&=(i&nums[i]);
        }
        return (res==INT_MAX)?0:res;
    }
};