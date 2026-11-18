class Solution {
public:
    int minChanges(const string& s) {
        int n=s.size(),res=0;
        if(n%2==1) return -1;
        for(int i=0;i<n;i+=2){
            if(s[i]!=s[i+1]) res++;
        }
        return res;
    }
};