class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>res; int idx=0,count=0;
        for(auto&n:nums){
            if(n<target) idx++;
            if(n==target) count++;
        }
        while(count>0){
            res.push_back(idx);
            count--,idx++;
        }
        return res;
    }
};