class Solution {
public:
    int t[501][501][3];
    int solve(int i,int j,int k,const int&n,const int&m,const vector<vector<int>>& coins){
        if(i==n-1&&j==m-1) return coins[i][j]>=0?coins[i][j]:((k>0)?0:coins[i][j]);
        if(i>=n||j>=m) return INT_MIN;
        if(t[i][j][k]!=INT_MIN) return t[i][j][k];
        if(coins[i][j]>=0){
            int res=coins[i][j];
            int res1=solve(i+1,j,k,n,m,coins);
            int res2=solve(i,j+1,k,n,m,coins);
            int m1=max(res1,res2);
            res=(m1!=INT_MIN)?res+m1:INT_MIN;
            return t[i][j][k]=res;
        }
        else{
            int res1=coins[i][j];
            int res2=(k>0)?0:INT_MIN;
            int res3=solve(i+1,j,k,n,m,coins);
            int res4=solve(i,j+1,k,n,m,coins);
            int res5=INT_MIN,res6=INT_MIN;
            if(k>0){
                res5=solve(i+1,j,k-1,n,m,coins);
                res6=solve(i,j+1,k-1,n,m,coins);
            }
            int m1=max(res3,res4);
            int m2=max(res5,res6);
            res1=(m1!=INT_MIN)?res1+m1:INT_MIN;
            res2=(m2!=INT_MIN && res2!=INT_MIN)?res2+m2:INT_MIN;
            return t[i][j][k]=max(res1,res2);
        }
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        fill(&t[0][0][0],&t[0][0][0]+sizeof(t)/sizeof(int),INT_MIN);
        return solve(0,0,2,n,m,coins);
    }
};