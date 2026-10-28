class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>max_deq,min_deq;
        int n=nums.size(),left=0,max_win_len=0;
        for(int right=0;right<n;right++){
            int curr=nums[right];
            while(max_deq.size()>0 && nums[max_deq.back()]<curr) max_deq.pop_back();
            while(min_deq.size()>0 && nums[min_deq.back()]>curr) min_deq.pop_back();
            max_deq.push_back(right); min_deq.push_back(right);
            while(nums[max_deq.front()]-nums[min_deq.front()]>limit){
                left=min(max_deq.front(),min_deq.front())+1;
                while(max_deq.front()<left) max_deq.pop_front();
                while(min_deq.front()<left) min_deq.pop_front();
            }
            max_win_len=max(max_win_len,right-left+1);
        }
        return max_win_len;
    }
};