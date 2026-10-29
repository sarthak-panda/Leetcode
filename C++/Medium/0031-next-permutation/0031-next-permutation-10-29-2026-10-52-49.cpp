class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i=n-2;
        //phase-1 : find pivot 'i'
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        //phase-2 : find swap with one that is just larger than ith
        if(i>=0){
            int j=n-1;
            while(nums[i]>=nums[j]) j--;
            swap(nums[i],nums[j]);
        }
        //phase-3 : reverse the from i+1 (inclusive) to end (n)
        reverse(nums.begin()+(i+1),nums.end());
    }
};