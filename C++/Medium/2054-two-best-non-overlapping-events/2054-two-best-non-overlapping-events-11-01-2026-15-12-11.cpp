int t[100001][3];
class Solution {
public:
    int solve(int idx,int budget,const int&n,const vector<vector<int>>& events){
        if(idx>=n) return 0;//we can't have ng bug so not handling that case in base
        if(t[idx][budget]!=-1) return t[idx][budget];
        int r1=0,r2=0;
        //skip
        r1=solve(idx+1,budget,n,events);
        //take
        if(budget>0){
            int curr_end=events[idx][1];
            // ineed to search for start that is geq to curr_end+1
            curr_end++;
            auto it=lower_bound(events.begin(),events.end(),curr_end,[](const auto&e,const int&x){
                return x>e[0];
            });
            int next_idx=distance(events.begin(),it);
            r2=solve(next_idx,budget-1,n,events);
            r2+=events[idx][2];
        }
        return t[idx][budget]=max(r1,r2);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        memset(t,-1,sizeof(t));
        sort(events.begin(),events.end(),[](const auto&a,const auto&b){
            return (a[0]<b[0])||((a[0]==b[0])&&(a[1]<b[1]));
        });
        int n=events.size();
        return solve(0,2,n,events);
    }
};