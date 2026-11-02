typedef long long ll;
const ll MOD=1e9+7;

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        map<int,int>events;
        for(auto&r:requests){
            events[r[0]]+=1;
            events[r[1]+1]-=1;
        }
        int n=nums.size();ll cnt=0;
        vector<ll>vals;vals.reserve(n);
        for(auto it=events.begin();it!=events.end();it++){
            cnt+=it->second;
            if(cnt!=0){
                int repeats=next(it)->first-it->first;
                while(repeats--) vals.push_back(cnt);
            }
        }
        sort(nums.begin(),nums.end(),greater<int>());
        sort(vals.begin(),vals.end(),greater<int>());
        ll res=0;
        for(int i=0;i<vals.size();i++){
            res=(res+(1LL*vals[i]*nums[i])%MOD)%MOD;
        }
        return static_cast<int>(res);
    }
};