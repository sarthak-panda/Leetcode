class Solution {
public:
    int MOD=1e9+7;
    vector<vector<int>>adj={
        {4,6},//0
        {6,8},//1
        {7,9},//2
        {4,8},//3
        {3,9,0},//4
        {},//5
        {1,7,0},//6
        {2,6},//7
        {1,3},//8
        {2,4}//9
    };
    int t[5001][10];
    int solve(int n,int cell){
        if(n==0) return 1;
        if(t[n][cell]!=-1) return t[n][cell];
        int ans=0;
        for(auto&nextCell:adj[cell]){
            ans=(ans+solve(n-1,nextCell))%MOD;
        }
        return t[n][cell]=ans;
    }
    int knightDialer(int n) {
        int res=0;
        memset(t,-1,sizeof(t));
        for(int cell=0;cell<=9;cell++){
            res=(res+solve(n-1,cell))%MOD;
        }
        return res;
    }
};