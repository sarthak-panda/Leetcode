class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        //min diff doesn't matter in all case it is zero
        int n=nums.size();
        if(n<=3) return 0;
        sort(nums.begin(),nums.end());
        vector<int>v={nums[0],nums[1],nums[2],nums[n-3],nums[n-2],nums[n-1]};
        int ri=5,li=0;
        //case-1 two from lefts
        int a1=v[ri]-v[li+2];
        //case-2 two from rights
        int a2=v[ri-2]-v[li];
        //case-3 one from left and right
        int a3=v[ri-1]-v[li+1];
        return min({a1,a2,a3});
    }
};