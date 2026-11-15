int MOD=1e9+7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>freq_mp={1,0};//(even_sum freq,odd sum freq), intial sum is 0, which is even
        int cumm_sum=0,res=0;
        for(int i=0;i<n;i++){
            cumm_sum+=arr[i];
            bool is_curr_odd=cumm_sum%2;
            res=(res+((is_curr_odd)?freq_mp[0]:freq_mp[1]))%MOD;//pairs with prev obtained even sums if curr odd or vice versa
            freq_mp[is_curr_odd]+=1;
        }
        return res;
    }
};