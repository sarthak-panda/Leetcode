class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size(),mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(i-j+1<=r && i-j+1>=l){
                    int s=0;
                    for(int k=j;k<=i;k++){
                        s+=nums[k];
                    }
                    if(s<=0) continue;
                    mini=min(mini,s);
                }
            }
        }
        return (mini==INT_MAX)?-1:mini;
    }
};