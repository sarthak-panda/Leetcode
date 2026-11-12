typedef long long ll;
const ll INF=1e16;
ll cost[100001];
ll t[16][100001];
class Solution {
public:
    int n,x,k;
    void fill_cost(const vector<int>& nums){
        multiset<int>left,right;
        int l=0; ll ls=0,rs=0;
        for(int r=0;r<n;r++){
            if(left.size()<=right.size()){
                left.insert(nums[r]);
                ls+=nums[r];
            }else{
                right.insert(nums[r]);
                rs+=nums[r];
            }
            //rebalancing
            if(right.size()>0 && (*left.rbegin())>(*right.begin())){
                int maxL=(*left.rbegin());
                int minR=(*right.begin());
                left.erase(prev(left.end()));
                right.erase(right.begin());
                left.insert(minR);
                right.insert(maxL);
                ls+=(minR-maxL);
                rs+=(maxL-minR);
            }
            if(left.size()+right.size()==x){
                ll median=*(left.rbegin());
                ll costL=median*left.size()-ls;
                ll costR=rs-median*right.size();
                cost[l]=costL+costR;
                if(left.find(nums[l])!=left.end()){
                    left.erase(left.find(nums[l]));
                    ls-=nums[l];
                }else{
                    right.erase(right.find(nums[l]));
                    rs-=nums[l];
                }
                l++;
            }
        }
    }
    ll solve(int idx,int count){
        if(count==k) return 0;
        if(t[count][idx]!=-1) return t[count][idx];
        int remaining_windows=(k-count);
        int remaining_elems=remaining_windows*x;
        int last_idx=idx+remaining_elems-1;
        if(last_idx>=n) return INF;
        ll r1=cost[idx]+solve(idx+x,count+1);
        ll r2=solve(idx+1,count);
        return t[count][idx]=min(r1,r2);
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        this->n=nums.size();
        this->x=x;
        this->k=k;
        memset(t,-1,sizeof(t));
        fill_cost(nums);
        return solve(0,0);
    }
};