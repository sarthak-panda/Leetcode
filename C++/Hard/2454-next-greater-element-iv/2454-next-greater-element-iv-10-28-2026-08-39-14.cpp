class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int K=2;
        vector<vector<int>>stks(K);//equivalent of vector<stack<int>>
        int n=nums.size();
        vector<int>res(n,-1);
        for(int i=0;i<n;i++){
            int x=nums[i];
            for(int k=K-1;k>=0;k--){
                vector<int>tmp_stk;
                while(!(stks[k].empty()) && (nums[stks[k].back()]<x)){
                    if(k!=K-1) tmp_stk.push_back(stks[k].back());
                    else res[stks[k].back()]=x;
                    stks[k].pop_back();
                }
                if(k!=K-1){
                    while(!tmp_stk.empty()){
                        stks[k+1].push_back(tmp_stk.back());
                        tmp_stk.pop_back();
                    }
                }
                if(k==0){
                    stks[0].push_back(i);
                }
            }
        }
        return res;
    }
};