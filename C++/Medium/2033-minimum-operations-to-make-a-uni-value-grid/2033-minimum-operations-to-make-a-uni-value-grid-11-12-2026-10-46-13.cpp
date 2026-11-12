class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> vec;
        vec.reserve(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec.push_back(grid[i][j]);
            }
        }
        int L=vec.size();
        nth_element(vec.begin(),vec.begin()+L/2,vec.end());
        int target=vec[L/2];
        int result=0;
        for(auto&num:vec){
            if(num%x!=target%x) return -1;
            result+=(abs(target-num))/x;
        }
        return result;
    }
};