class Solution {
public:
    typedef pair<int,int>pi;
    int longestSubarray(vector<int>& nums, int limit) {
        deque<pi>max_deq,min_deq;
        int n=nums.size(),left=0,max_win_len=0;
        for(int right=0;right<n;right++){
            int curr=nums[right];
            while(max_deq.size()>0 && max_deq.back().first<curr) max_deq.pop_back();
            while(min_deq.size()>0 && min_deq.back().first>curr) min_deq.pop_back();
            max_deq.push_back({curr,right}); min_deq.push_back({curr,right});
            while(max_deq.front().first-min_deq.front().first>limit){
                left=min(max_deq.front().second,min_deq.front().second)+1;
                while(max_deq.front().second<left) max_deq.pop_front();
                while(min_deq.front().second<left) min_deq.pop_front();
            }
            max_win_len=max(max_win_len,right-left+1);
        }
        return max_win_len;
    }
};