class Solution {
public:
    vector<int> computeLPS(const vector<int>&pat){
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
    int firstMatchKMP(const vector<int>&txt,const vector<int>&pat){
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
    bool isRotation(vector<int>&vec2,vector<int>&vec1){
        //just check using kmp if vec2 is subvector of vec1
        int idx=firstMatchKMP(vec1, vec2);
        return idx!=-1;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted_nums=nums;
        sort(sorted_nums.begin(),sorted_nums.end());
        int res=0;
        for(int k=1;k<=n;k++){
            if(n%k==0){
                bool is_val=true;
                for(int i=0;i<n;i+=k){
                    vector<int>vec1(sorted_nums.begin()+i,sorted_nums.begin()+i+k);
                    vector<int>vec2(nums.begin()+i,nums.begin()+i+k);
                    auto temp=vec1;
                    vec1.insert(vec1.end(),temp.begin(),temp.end());
                    if(!isRotation(vec2,vec1)) {is_val=false;break;}
                }
                if(is_val) res+=k;
            }
        }
        return res;
    }
};