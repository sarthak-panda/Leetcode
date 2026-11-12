class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>left,right;
        int l=0,n=nums.size();
        vector<double>res; res.reserve(n-k+1);
        
        for(int r=0;r<n;r++){
            //erase old one before inserting
            if(left.size()+right.size()==k){
                auto it=left.find(nums[l]);
                if(it!=left.end()) left.erase(it);
                else right.erase(right.find(nums[l]));
                l++;
            }

            //insert incoming// we will maintain left size = right size or left size=rightsize+1
            if(left.empty()){
                if(right.empty() || nums[r]<=*(right.begin())) left.insert(nums[r]);
                else right.insert(nums[r]);
            }
            else if(nums[r]<=*(left.rbegin())) left.insert(nums[r]);
            else right.insert(nums[r]);

            //re-balance/correction
            if(left.size()>right.size()+1){
                auto it=prev(left.end());
                right.insert(*it);
                left.erase(it);
            }
            else if(left.size()<right.size()){
                auto it=right.begin();
                left.insert(*it);
                right.erase(it);
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