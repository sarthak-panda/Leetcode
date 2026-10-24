class Solution {
public:
    double myPow(double x, int n) {
        bool pos=(n>=0);
        long long n_ll=abs(1LL*n); double curr=x,res=1;
        for(int i=0;i<=32;i++){
            if(n_ll>>i & 1) res*=curr;
            curr*=curr;
        }
        return (pos)?res:(1.0/res);
    }
};