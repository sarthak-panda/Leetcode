class Solution {
public:
    int t[501][502];
    int solve(int idx,int numWallsLeft,const int&n,const vector<int>& cost,const vector<int>& time){
        if(numWallsLeft<=0) return 0;//no more cost incurred
        if(idx>=n) return INT_MAX;//walls left to be painted even after covering all idxs, infinite cost to paiint them
        if(t[idx][numWallsLeft]!=-1) return t[idx][numWallsLeft];
        int r1=solve(idx+1,numWallsLeft-1-time[idx],n,cost,time);//used paid painter
        int r2=solve(idx+1,numWallsLeft,n,cost,time);//not used paid painter, hope free one will cover
        if(r1!=INT_MAX) r1+=cost[idx];
        return t[idx][numWallsLeft]=min(r1,r2);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(t,-1,sizeof(t));
        int n=cost.size();
        return solve(0,n,n,cost,time);
    }
};