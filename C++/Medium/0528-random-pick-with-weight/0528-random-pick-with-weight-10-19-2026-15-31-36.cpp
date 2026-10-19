class Solution {
public:
    int scale=1;
    vector<int>prefix;
    Solution(vector<int>& w) {
        prefix={0};
        for(auto&x:w) prefix.push_back(prefix.back()+x);
        scale=prefix.back();
    }
    
    int pickIndex() {
        double r=(1.0*rand())/RAND_MAX;
        double target=r*scale;
        int idx=lower_bound(prefix.begin(),prefix.end(),target)-prefix.begin();
        return idx-1;//see idx can't never be zero all numbers are greater thaan zero and lower bound gives first num in >= target, furst landing in 1st region corresponds to 0 th index being picked up in original array
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */