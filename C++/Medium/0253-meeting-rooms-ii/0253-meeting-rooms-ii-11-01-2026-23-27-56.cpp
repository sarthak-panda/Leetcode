class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](const auto&a,const auto&b){
            return (a[0]<b[0])||(a[0]==b[0]&&a[1]<b[1]);
        });
        int curr_meeting_rooms=1,max_rooms=1;
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(intervals[0][1]);
        for(int i=1;i<n;i++){
            int curr_ending_time=pq.top(); pq.pop();
            if(intervals[i][0]>=curr_ending_time) pq.push(intervals[i][1]);
            else curr_meeting_rooms++,pq.push(curr_ending_time),pq.push(intervals[i][1]),max_rooms=max(max_rooms,curr_meeting_rooms);
        }
        return max_rooms;
    }
};