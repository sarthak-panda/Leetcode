class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        next_permutation(s.begin(),s.end());
        long long z=stoll(s);
        if(z>INT_MAX||z<=n) return -1;//z<n, is the case where next_permut moves [3,2,1] to [1,2,3] or [1] to [1] for equal case
        return static_cast<int>(z);
    }
};