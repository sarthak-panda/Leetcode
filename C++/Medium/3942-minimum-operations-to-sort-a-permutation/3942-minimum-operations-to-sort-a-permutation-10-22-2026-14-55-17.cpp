class Solution {
public:
    bool checkIncreasing(const vector<int>& nums,int minIdx){
        int i=minIdx,n=nums.size();
        while(nums[(i+1)%n]-1==nums[i%n]) i++;
        return ((i+1)%n==minIdx);
    }
    int minOperations(vector<int>& nums) {
        int minIdx,n=nums.size();
        for(int i=0;i<n;i++) if(nums[i]==0) minIdx=i;
        bool is_increasing=false,is_decreasing=false;
        is_increasing=checkIncreasing(nums,minIdx);
        if(!is_increasing){
            reverse(nums.begin(),nums.end());
            minIdx=(n-1)-minIdx;
            is_decreasing=checkIncreasing(nums,minIdx);
        }
        if(!is_increasing && !is_decreasing) return -1;
        if(is_increasing) return min(minIdx,2+(n-minIdx));
        else/*is_decreasing*/ return min(1+(n-minIdx),1+minIdx);
    }
};