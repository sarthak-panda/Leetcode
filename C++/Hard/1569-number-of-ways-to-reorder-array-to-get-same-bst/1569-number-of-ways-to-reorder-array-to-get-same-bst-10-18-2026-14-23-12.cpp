class Solution {
public:
    typedef long long ll;
    ll MOD=1e9+7;
    vector<vector<int>>PT;
    int solve(const vector<int>&nums){
        int n=nums.size();
        if(n<3) return 1;
        vector<int>leftArr,rightArr;
        int root=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<root) leftArr.push_back(nums[i]);
            else rightArr.push_back(nums[i]);
        }
        ll x=solve(leftArr);
        ll y=solve(rightArr);
        ll z=PT[n-1][leftArr.size()];
        return (((x*y)%MOD)*z)%MOD;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        PT.resize(n);
        for(int i=0;i<n;i++){
            PT[i]=vector<int>(i+1,1);
            for(int j=1;j<i;j++) PT[i][j]=(PT[i-1][j]+PT[i-1][j-1])%MOD;
        }
        return solve(nums)-1;
    }
};