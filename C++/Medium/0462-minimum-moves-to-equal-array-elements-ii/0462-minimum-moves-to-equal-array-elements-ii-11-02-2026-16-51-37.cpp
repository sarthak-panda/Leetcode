class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int median1=nums[n/2];
        int moves_to_median=0;
        for(auto&x:nums){
            moves_to_median+=abs(x-median1);
        }
        return moves_to_median;
    }
};