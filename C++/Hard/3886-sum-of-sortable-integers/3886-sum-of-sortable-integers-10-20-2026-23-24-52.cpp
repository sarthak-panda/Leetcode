class Solution {
public:
    // 1. Pass a pre-allocated 'lps' vector by reference to avoid re-allocating
    void computeLPS(const vector<int>&pat, vector<int>& lps){
        int n=pat.size();
        lps.assign(n, 0); // .assign() reuses memory instead of creating a new vector
        int j=0;
        for(int i=1;i<n;i++){
            while(j>0 && pat[i]!=pat[j]) j=lps[j-1];
            if(pat[i]==pat[j]) j++;
            lps[i]=j;
        }
    }

    int firstMatchKMP(const vector<int>&txt, const vector<int>&pat, vector<int>& lps){
        if(pat.empty()) return -1;
        int n=txt.size(), m=pat.size();
        computeLPS(pat, lps);
        int j=0;
        for(int i=0;i<n;i++){
            while(j>0 && txt[i]!=pat[j]) j=lps[j-1];
            if(txt[i]==pat[j]) j++;
            if(j==m) return i-(m-1);
        }
        return -1;
    }

    bool isRotation(const vector<int>&vec2, const vector<int>&vec1, vector<int>& lps){
        int idx=firstMatchKMP(vec1, vec2, lps);
        return idx!=-1;
    }

    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted_nums=nums;
        sort(sorted_nums.begin(),sorted_nums.end());
        int res=0;
        
        // 2. Declare vectors ONCE outside the loops
        vector<int> vec1;
        vector<int> vec2;
        vector<int> lps;
        
        // Pre-allocate maximum required capacities
        vec1.reserve(2 * n);
        vec2.reserve(n);
        lps.reserve(n);
        
        for(int k=1;k<=n;k++){
            if(n%k==0){
                bool is_val=true;
                for(int i=0;i<n;i+=k){
                    // 3. Overwrite existing memory using .assign() instead of creating new objects
                    vec1.assign(sorted_nums.begin()+i, sorted_nums.begin()+i+k);
                    vec2.assign(nums.begin()+i, nums.begin()+i+k);
                    
                    // Directly append to vec1 (eliminates the need for 'temp')
                    vec1.insert(vec1.end(), sorted_nums.begin()+i, sorted_nums.begin()+i+k);
                    
                    if(!isRotation(vec2, vec1, lps)) {
                        is_val=false;
                        break;
                    }
                }
                if(is_val) res+=k;
            }
        }
        return res;
    }
};