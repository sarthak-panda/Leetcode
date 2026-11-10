// int t[100005];
class Solution {
public:
    // int solve(int idx,const int&n,const vector<int>& costs){
    //     if(idx==(n-1)) return 0;
    //     if(idx!=-1 && t[idx]!=-1) return t[idx];
    //     int r1=INT_MAX,r2=INT_MAX,r3=INT_MAX;
    //     if(idx+1<n) r1=solve(idx+1,n,costs)+costs[idx+1]+1;
    //     if(idx+2<n) r2=solve(idx+2,n,costs)+costs[idx+2]+4;
    //     if(idx+3<n) r3=solve(idx+3,n,costs)+costs[idx+3]+9;
    //     int r=min({r1,r2,r3});
    //     if(idx!=-1) t[idx]=r;
    //     return r;
    // }
    int climbStairs(int n, vector<int>& costs) {
        // memset(t,-1,sizeof(t));
        // return solve(-1,n,costs);
        int p,pp,ppp;
        for(int idx=n-1;idx>=-1;idx--){
            if(idx==(n-1)) {p=pp=ppp=0; continue;}
            int r1=INT_MAX,r2=INT_MAX,r3=INT_MAX;
            if(idx+1<n) r1=p+costs[idx+1]+1;
            if(idx+2<n) r2=pp+costs[idx+2]+4;
            if(idx+3<n) r3=ppp+costs[idx+3]+9;
            ppp=pp,pp=p,p=min({r1,r2,r3});
        }
        return p;
    }
};