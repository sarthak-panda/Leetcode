typedef long long ll;
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        //min(cost1*a+cost2*b+costBoth*c)
        //type1: a+c>=need1
        //type2: b+c>=need2
        int A=cost1,B=cost2,C=costBoth;
        int E=need1,F=need2;
        vector<array<int,3>>feasibles;
        //let us find corner points, optimal at corner point
        if(F>E) feasibles={{0,0,max(E,F)},{E,F,0},{0,F-E,E}};
        else if(E>F) feasibles={{0,0,max(E,F)},{E,F,0},{E-F,0,F}};
        else feasibles={{0,0,max(E,F)},{E,F,0}};
        ll minCost=LLONG_MAX,currCost;
        for(auto&[a,b,c]:feasibles){
            currCost=1LL*A*a+1LL*B*b+1LL*C*c;
            minCost=min(minCost,currCost);
        }
        return minCost;
    }
};