class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),[](const auto&a,const auto&b){
            return (a[1]<b[1])||(a[1]==b[1] && a[0]<b[0]);
        });
        int arrows=1;
        int last_arrow_coord=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]>last_arrow_coord){
                arrows++;
                last_arrow_coord=points[i][1];
            }
        }
        return arrows;
    }
};