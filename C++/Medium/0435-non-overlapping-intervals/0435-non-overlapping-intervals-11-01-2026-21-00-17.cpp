class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const auto&a,const auto&b){
            return (a[1]<b[1])||((a[1]==b[1]) && (a[0]<b[0]));
        });
        auto prev_interval=intervals[0]; int count=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prev_interval[1]) count++;
            else prev_interval=intervals[i];
        }
        return count;
    }
};