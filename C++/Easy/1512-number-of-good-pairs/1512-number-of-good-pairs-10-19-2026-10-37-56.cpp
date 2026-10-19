class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        array<int,101>freq; freq.fill(0); int count=0;
        for(auto&n:nums) count+=freq[n],freq[n]++;
        return count;
    }
};