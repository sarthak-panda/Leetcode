const int MAXN=100004;
const int LOG_H=20;
int up[MAXN][LOG_H+1];

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>>arr(n); vector<int>origIdxToSortedIdx(n);
        for(int i=0;i<n;i++) arr[i]={nums[i],i};
        sort(arr.begin(),arr.end());
        for(int i=n-1;i>=0;i--){
            int curr_num=arr[i].first,orig_idx=arr[i].second;
            origIdxToSortedIdx[orig_idx]=i;

            int farthest_reachable_val=curr_num+maxDiff;
            auto it=upper_bound(arr.begin()+i,arr.end(),farthest_reachable_val,[](const int& x,const pair<int,int>&a){
                return a.first>x;
            });
            int farthest_reachable_idx=distance(arr.begin(),it)-1;

            up[i][0]=farthest_reachable_idx;
            for(int j=1;j<=LOG_H;j++) up[i][j]=up[up[i][j-1]][j-1];
        }
        int nq=queries.size();
        vector<int>res(nq);
        for(int i=0;i<nq;i++){
            int a=origIdxToSortedIdx[queries[i][0]],b=origIdxToSortedIdx[queries[i][1]];
            if(a==b) {res[i]=0;continue;}
            if(a>b) swap(a,b);
            int curr=a,jumps=0;
            for(int j=LOG_H;j>=0;j--){
                if(up[curr][j]<b){
                    curr=up[curr][j];
                    jumps+=(1<<j);
                }
            }
            if(up[curr][0]>=b) jumps+=1,res[i]=jumps;
            else if(up[curr][0]<b) res[i]=-1;
        }
        return res;
    }
};