class Solution {
public:
    typedef pair<int,int>pi;
    int longestSubarray(vector<int>& nums, int limit) {
        priority_queue<pi>mx_heap;
        priority_queue<pi,vector<pi>,greater<pi>>mn_heap;
        int n=nums.size(),left=0,max_win_len=0;
        for(int right=0;right<n;right++){
            mx_heap.push({nums[right],right});
            mn_heap.push({nums[right],right});
            while(mx_heap.top().first-mn_heap.top().first>limit){
                left=min(mx_heap.top().second,mn_heap.top().second)+1;
                while(mx_heap.top().second<left) mx_heap.pop();
                while(mn_heap.top().second<left) mn_heap.pop();
            }
            max_win_len=max(max_win_len,right-left+1);
        }
        return max_win_len;
    }
};