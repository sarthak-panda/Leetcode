class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end()); int m=arr2.size();
        int count=0;
        for(auto&x:arr1){
            bool valid=true;
            auto it=lower_bound(arr2.begin(),arr2.end(),x);
            int idx=distance(arr2.begin(),it);
            if(idx<m && arr2[idx]-x<=d) valid=false;
            if(idx-1>=0 && x-arr2[idx-1]<=d) valid=false;
            if(valid) count++; 
        }
        return count;
    }
};