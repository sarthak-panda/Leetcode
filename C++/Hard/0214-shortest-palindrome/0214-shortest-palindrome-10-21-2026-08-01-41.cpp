class Solution {
public:
    vector<int> computeLPS(const string&pat){
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
    string shortestPalindrome(string s) {
        int n=s.size();
        string rev_string=s;
        reverse(rev_string.begin(),rev_string.end());
        string final_string=s+'#'+rev_string;
        vector<int>lps=computeLPS(final_string);
        int len_longest_palindrome=lps.back();
        int len_of_trailing_tail_unmatched=n-len_longest_palindrome;
        string trail=s.substr(n-len_of_trailing_tail_unmatched,len_of_trailing_tail_unmatched);
        reverse(trail.begin(),trail.end());
        trail+=s;
        return trail;
    }
};