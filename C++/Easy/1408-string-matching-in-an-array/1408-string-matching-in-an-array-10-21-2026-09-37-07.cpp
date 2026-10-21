class Solution {
public:
    vector<int> constructLPS(const string&pat){
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
    int getFirstMatchKMP(const string&txt,const string&pat){
        int n=txt.size(),m=pat.size();
        vector<int>lps=constructLPS(pat);
        int j=0;
        for(int i=0;i<n;i++){
            while(j>0 && txt[i]!=pat[j]) j=lps[j-1];
            if(txt[i]==pat[j]) j++;
            if(j==m) return i-(m-1);
        }
        return -1;
    }
    bool check_substr(const string&txt,const string&pat){
        return (getFirstMatchKMP(txt,pat)!=-1);
    }
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size(); unordered_set<string>res; res.reserve(n);
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++){
            int la=words[i].size(),lb=words[j].size();
            if(la>lb && check_substr(words[i],words[j])) res.insert(words[j]);
            else if(lb>la && check_substr(words[j],words[i])) res.insert(words[i]);
        }
        return {res.begin(),res.end()};
    }
};