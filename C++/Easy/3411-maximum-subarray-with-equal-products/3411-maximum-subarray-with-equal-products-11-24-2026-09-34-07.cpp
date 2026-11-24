class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res=2,l=0,running_product=1,n=nums.size();
        for(int r=0;r<n;r++){
            while(gcd(running_product,nums[r])>1){//coprime check, not a running gcd, incoming is coprime to existing or not
                running_product/=nums[l]; l++;
            }
            running_product*=nums[r];
            res=max(res,r-l+1);
        }
        return res;
    }
};