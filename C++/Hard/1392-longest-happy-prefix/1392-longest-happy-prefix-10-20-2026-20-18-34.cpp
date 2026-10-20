class Solution {
public:
    vector<int> computeLPS(const string& pat){
        int n=pat.size();
        vector<int>lps(n,0);
        int j=0;
        for(int i=1;i<n;i++){
            while(j>0 && pat[i]!=pat[j]) j=lps[j-1];
            if(pat[i]==pat[j]) j++;
            lps[i]=j;
        }
        return lps;
    }
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps=computeLPS(s);
        int idx=lps[n-1];
        return s.substr(0,idx);
    }
};