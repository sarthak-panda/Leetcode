struct Job{
    int start;
    int end;
    int profit;
};
int t[50005];
class Solution {
public:
    int solve(int idx,int n,const vector<Job>&Jobs){
        if(idx>=n) return 0;
        if(t[idx]!=-1) return t[idx];
        int r1=0,r2=0;
        //skip
        r1=solve(idx+1,n,Jobs);
        //take
        int curr_end=Jobs[idx].end;
        auto it=lower_bound(Jobs.begin(),Jobs.end(),curr_end,[](const auto&r,const int& x){
            return x>r.start;
        });
        int next_idx=distance(Jobs.begin(),it);
        r2=solve(next_idx,n,Jobs);
        return t[idx]=max(r1,Jobs[idx].profit+r2);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(t,-1,sizeof(t));
        int n=startTime.size();
        vector<Job>Jobs(n);
        for(int i=0;i<n;i++) Jobs[i]={startTime[i],endTime[i],profit[i]};
        sort(Jobs.begin(),Jobs.end(),[](const auto&a,const auto&b){
            return (a.start<b.start)||(a.start==b.start && a.end<b.end);
        });
        return solve(0,n,Jobs);
    }
};