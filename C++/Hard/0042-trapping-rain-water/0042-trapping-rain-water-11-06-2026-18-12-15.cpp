class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>st; int n=height.size(),ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && height[st.back()]<height[i]){
                int curr_height=height[st.back()]; st.pop_back();
                int non_inclusive_start=(!st.empty())?st.back():-1;
                if(non_inclusive_start==-1) continue;
                int non_inclusive_end=i;
                int width=non_inclusive_end-non_inclusive_start-1;
                int extra_height=min(height[non_inclusive_start],height[non_inclusive_end])-curr_height;
                ans+=(extra_height*width);
            }
            st.push_back(i);
        }
        return ans;
    }
};