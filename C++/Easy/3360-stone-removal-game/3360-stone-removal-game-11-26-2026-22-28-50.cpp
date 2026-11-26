class Solution {
public:
    bool canAliceWin(int n) {
        for(int i=10;i>=1;i--){
            if(n>=i) n-=i;
            else return (i%2);
        }
        return false;
    }
};