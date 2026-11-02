class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>>events;
        for(auto&t:trips){
            events.push_back({t[1],t[0]});
            events.push_back({t[2],-1*t[0]});
        }
        sort(events.begin(),events.end());
        int cumm_cnt=0;
        for(auto&[t,p]:events){
            cumm_cnt+=p;
            if(cumm_cnt>capacity) return false;
        }
        return true;
    }
};