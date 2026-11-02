typedef long long ll;
const ll MOD=1e9+7;

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        vector<int>events(n+1,0);
        for(auto&r:requests){
            events[r[0]]+=1;
            events[r[1]+1]-=1;
        }
        ll cnt=0;
        vector<ll>vals(n,0);vals.reserve(n); int ix=0;
        for(int ix=0;ix<n;ix++){
            cnt+=events[ix];
            vals[ix]=(cnt);
        }
        sort(nums.begin(),nums.end(),greater<int>());
        sort(vals.begin(),vals.end(),greater<ll>());
        ll res=0;
        for(int i=0;i<n;i++){
            res=(res+(1LL*vals[i]*nums[i])%MOD)%MOD;
        }
        return static_cast<int>(res);
    }
};