
class Solution {
public:
    vector<int> pre;
    int sum = 0;

    Solution(vector<int>& w) {
        for(int x : w) {
            sum += x;
            pre.push_back(sum);
        }
    }
    
    int pickIndex() {
        int x = rand() % sum + 1;

        int i = lower_bound(pre.begin(), pre.end(), x) - pre.begin();

        return i;
    }
};