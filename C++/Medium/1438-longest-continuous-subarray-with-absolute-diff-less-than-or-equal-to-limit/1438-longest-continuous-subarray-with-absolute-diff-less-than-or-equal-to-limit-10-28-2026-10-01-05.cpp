class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left=0,max_win_len=INT_MIN,n=nums.size();
        multiset<int>window;
        for(int right=0;right<n;right++){
            window.insert(nums[right]);
            while(*window.rbegin()-*window.begin()>limit){
                window.erase(window.find(nums[left]));
                left++;
            }
            int curr_win_len=window.size();
            max_win_len=max(max_win_len,curr_win_len);
        }
        return max_win_len;
    }
};