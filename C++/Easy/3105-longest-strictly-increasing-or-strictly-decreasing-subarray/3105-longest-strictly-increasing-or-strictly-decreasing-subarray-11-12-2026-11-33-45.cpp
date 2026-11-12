class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int count=1;
        int inc_phase=0;//0 no phae,1 inc phase,2 dec phase
        int max_cnt=1,n=nums.size();
        for(int i=1;i<n;i++){
            int curr_diff=nums[i]-nums[i-1];
            if(curr_diff>0){
                if(inc_phase==1) count+=1,max_cnt=max(max_cnt,count);
                else count=2,inc_phase=1,max_cnt=max(max_cnt,count);
            }else if(curr_diff<0){
                if(inc_phase==2) count+=1,max_cnt=max(max_cnt,count);
                else count=2,inc_phase=2,max_cnt=max(max_cnt,count);
            }else{
                count=1,inc_phase=0;
            }
        }
        return max_cnt;
    }
};