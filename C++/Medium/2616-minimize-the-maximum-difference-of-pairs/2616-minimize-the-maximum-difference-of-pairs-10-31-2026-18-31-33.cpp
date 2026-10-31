bool feasible(int maxDiff,const int&n,const int&p,const vector<int>& nums){
    int i=0,count=0;
    while(i+1<n){
        if((nums[i+1]-nums[i])<=maxDiff) count++,i+=2;
        else i+=1;
    }
    return (count>=p);
}

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end()); int n=nums.size();
        int l=0,r=nums.back()-nums.front();
        while(l<r){
            int mid=(l+r)/2;
            if(feasible(mid,n,p,nums)) r=mid;
            else l=mid+1;
        }
        return r;
    }
};