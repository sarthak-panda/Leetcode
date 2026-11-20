int t[100001][2];

class Solution {
public:
    int find_elm(int start_idx,int v,const vector<int>& nums){
        auto it=lower_bound(nums.begin()+start_idx,nums.end(),v);
        if(it==nums.end()||(*it!=v)) return -1;
        return distance(nums.begin(),it);
    }
    int solve(int idx,int inc,const vector<int>& nums){
        int curr_val=nums[idx]+inc,res=1;
        if(t[idx][inc]!=-1) return t[idx][inc];
        //direct find curr_val+1
        int j=find_elm(idx+1,curr_val+1,nums);
        if(j!=-1) res=max(res,1+solve(j,0,nums));
        //find curr_val and inc 1 there
        j=find_elm(idx+1,curr_val,nums);
        if(j!=-1) res=max(res,1+solve(j,1,nums));
        return t[idx][inc]=res;
    }
    int maxSelectedElements(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        sort(nums.begin(),nums.end());
        int n=nums.size(),res=1;
        for(int i=0;i<n;i++){
            res=max(res,solve(i,0,nums));
            res=max(res,solve(i,1,nums));
        }
        return res;
    }
};