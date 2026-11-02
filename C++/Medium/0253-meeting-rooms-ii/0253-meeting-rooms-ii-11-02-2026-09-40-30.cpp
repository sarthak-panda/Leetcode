class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int>events;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            events[intervals[i][0]]++;
            events[intervals[i][1]]--;
        }
        int overlaps=0;
        int max_overlaps=0;
        for(auto&it:events){
            overlaps+=it.second;
            if(overlaps>max_overlaps) max_overlaps=overlaps;
        }
        return max_overlaps;
    }
};