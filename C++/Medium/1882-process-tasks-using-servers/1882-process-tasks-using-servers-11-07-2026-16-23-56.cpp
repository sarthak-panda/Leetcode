typedef long long ll;
typedef array<ll,3> a3;
typedef array<ll,2> a2;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<a2,vector<a2>,greater<a2>> free;//server weight,server index
        priority_queue<a3,vector<a3>,greater<a3>> occupied;//completion time,server weight,server index
        int n=servers.size(),m=tasks.size();
        for(int i=0;i<n;i++) free.push({servers[i],i});
        vector<int>ans(m);
        for(int i=0;i<m;i++){//i is current ideal start of tasks
            //befiore checking/picking server first move all occupied whose
            //completion time<=i (current time) to free;
            while(!occupied.empty() && (occupied.top())[0]<=i){
                free.push({occupied.top()[1],occupied.top()[2]});
                occupied.pop();
            }
            if(!free.empty()){
                auto [server_wgt,server_idx]=free.top(); free.pop();
                ans[i]=server_idx;
                occupied.push({i+tasks[i],server_wgt,server_idx});
            }else{
                auto [old_completion_time,server_wgt,server_idx]=occupied.top();
                occupied.pop(); ans[i]=server_idx;
                occupied.push({old_completion_time+tasks[i],server_wgt,server_idx});
            }
        }
        return ans;
    }
};