class Solution {
public:
    vector<int> computeLPS(const string&pat){
        int n=pat.size();
        vector<int>lps(n,0);
        int j=0;//denotes length of matching prefix
        for(int i=1;i<n;i++){
            while(j>0 && pat[i]!=pat[j]) j=lps[j-1];
            if(pat[i]==pat[j]) j++;
            lps[i]=j;
        }
        return lps;
    }
    vector<int> searchAllKMP(const string&txt,const string&pat){
        vector<int>result;
        if(pat.empty()) return result;
        int n=txt.size(),m=pat.size();
        vector<int>lps=computeLPS(pat);
        int j=0;//denotes how much of pattern we have matched so far
        for(int i=0;i<n;i++){
            //exactly same logic as compute, same fallback
            while(j>0 && txt[i]!=pat[j]) j=lps[j-1];
            if(txt[i]==pat[j]) j++;
            //full match found
            if(j==m){
                result.push_back(i-m+1);//starting index
                j=lps[j-1];//restart from one step fall for new matchings
            }
        }
        return result;
    }
    int firstMatchKMP(const string&txt,const string&pat){
        if(pat.empty()) return -1;
        int n=txt.size(),m=pat.size();
        vector<int>lps=computeLPS(pat);
        int j=0;
        for(int i=0;i<n;i++){
            while(j>0 && txt[i]!=pat[j]) j=lps[j-1];
            if(txt[i]==pat[j]) j++;
            if(j==m) return i-(m-1);
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        return firstMatchKMP(haystack, needle);
    }
};