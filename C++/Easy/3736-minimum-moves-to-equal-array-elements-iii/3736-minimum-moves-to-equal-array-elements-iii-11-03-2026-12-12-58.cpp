class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        return accumulate(nums.begin(),nums.end(),0,[&](int acc,int x){
            return acc+(maxi-x);
        });
    }
};