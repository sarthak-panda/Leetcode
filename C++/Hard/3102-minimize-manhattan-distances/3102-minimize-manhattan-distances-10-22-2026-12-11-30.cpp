class Solution {
public:
    vector<int> maxManhattanDistance(const vector<vector<int>>& points,int excludeID){//standard O(n) max manhattan
        vector<int>res={INT_MIN,-1,-1};
        pair<int,int>minSum={INT_MAX,-1},maxSum={INT_MIN,-1},minDiff={INT_MAX,-1},maxDiff={INT_MIN,-1};
        int num_points=points.size();
        for(int i=0;i<num_points;i++){
            if(i==excludeID) continue;
            int currSum=points[i][0]+points[i][1];
            int currDiff=points[i][0]-points[i][1];
            if(currSum<minSum.first) minSum.first=currSum,minSum.second=i;
            if(currSum>maxSum.first) maxSum.first=currSum,maxSum.second=i;
            if(currDiff<minDiff.first) minDiff.first=currDiff,minDiff.second=i;
            if(currDiff>maxDiff.first) maxDiff.first=currDiff,maxDiff.second=i;
        }
        if(maxSum.first-minSum.first>maxDiff.first-minDiff.first){
            res[0]=maxSum.first-minSum.first;
            res[1]=maxSum.second;
            res[2]=minSum.second;
        }
        else{
            res[0]=maxDiff.first-minDiff.first;
            res[1]=maxDiff.second;
            res[2]=minDiff.second;
        }
        return res;
    }
    int minimumDistance(const vector<vector<int>>& points) {
        auto res=maxManhattanDistance(points,-1);
        int i=res[1],j=res[2];//exclusion points choices, ie which are creating maximal pair are best choices for removal
        return min(maxManhattanDistance(points,i)[0],maxManhattanDistance(points,j)[0]);
    }
};