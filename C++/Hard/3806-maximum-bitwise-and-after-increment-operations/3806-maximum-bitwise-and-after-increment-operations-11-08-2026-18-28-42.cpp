class Solution {
public:
    int cost(int x,int target_bits){
        bool copy_from_x_phase=true;
        int ans=0;
        for(int i=30;i>=0;i--){
            if(!((x>>i)&1) && ((target_bits>>i)&1)) copy_from_x_phase=false;
            if(copy_from_x_phase) ans|=(x&(1<<i));
            else ans|=(target_bits&(1<<i));//copy from target,since just greater is done
        }
        return ans-x;
    }
    int maximumAND(vector<int>& nums, int k, int m) {
        int ans=0,n=nums.size();
        vector<int>costs(n);
        for(int i=30;i>=0;i--){
            for(int j=0;j<n;j++){
                costs[j]=(cost(nums[j],ans|(1<<i)));
            }
            //sort(costs.begin(),costs.end());
            nth_element(costs.begin(),costs.begin()+m,costs.end());
            long long s=accumulate(costs.begin(),costs.begin()+m,0LL);
            if(s<=k) ans|=(1<<i);
        }
        return ans;
    }
};