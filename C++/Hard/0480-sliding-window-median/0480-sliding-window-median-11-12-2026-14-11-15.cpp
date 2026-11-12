class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>left,right;
        int l=0,n=nums.size();
        vector<double>res; res.reserve(n-k+2);
        for(int r=0;r<n;r++){
            //erase old one before inserting
            if(left.size()+right.size()==k){
                if(right.empty() || (nums[l]<*(right.begin()))){
                    left.erase(left.find(nums[l]));
                }else{
                    right.erase(right.find(nums[l]));
                }
                l++;
            }
            //insert incoming// we will maintain left size = right size or left size=rightsize+1
            if(left.size()<=right.size()) left.insert(nums[r]);
            else right.insert(nums[r]);
            //re-balance/correction
            if(right.size()>=1 && *(left.rbegin())>*(right.begin())){
                int a=*(left.rbegin()),b=*(right.begin());
                left.erase(prev(left.end()));
                right.erase(right.begin());
                left.insert(b),right.insert(a);
            }
            //get median if win size k;
            if(left.size()+right.size()==k){
                double win_median;
                if(k%2==0) win_median=(static_cast<double>(*(left.rbegin()))+(*(right.begin())))/(static_cast<double>(2));
                else win_median=(*(left.rbegin()));
                res.push_back(win_median);
            }
        }
        return res;
    }
};