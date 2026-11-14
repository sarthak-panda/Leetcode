int t[11][301];
class Solution {
public:
    int solve(int d,int idx,const int& n,const vector<int>& jobDifficulty){
        if(d==1){//Base Case
            return (*max_element(jobDifficulty.begin()+idx,jobDifficulty.end()));
        }
        if(t[d][idx]!=-1) return t[d][idx];
        int max_running_difficulty=INT_MIN,min_res=INT_MAX;
        for(int i=idx;i<=n-d;i++){
            max_running_difficulty=max(max_running_difficulty,jobDifficulty[i]);
            int res=max_running_difficulty+solve(d-1,i+1,n,jobDifficulty);
            min_res=min(min_res,res);
        }
        return t[d][idx]=min_res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        memset(t,-1,sizeof(t));
        return solve(d,0,n,jobDifficulty);
    }
};