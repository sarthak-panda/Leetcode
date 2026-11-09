typedef pair<int,int> pii;
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        //Idea
        //to tackle circularity we can think of 2*k freq/flag array
        //and find the leftmost index just active post i%k.

        //Intializations
        int n=arrival.size();
        set<int>currently_free;//stores the index of currently free servers
        priority_queue<pii,vector<pii>,greater<pii>>completion_times;//stores {comp time,idx} of active servers
        vector<pii>num_times_assigned(k);
        for(int i=0;i<k;i++) currently_free.insert(i),currently_free.insert(i+k),num_times_assigned[i]={0,i};

        //Helper Labmdas
        auto toggle=[&](int idx,bool make_it_free){
            if(make_it_free) currently_free.insert(idx);
            else currently_free.erase(idx);
        };
        auto leftmost_free_server=[&](int idx){//assumes window size k;
            auto it=currently_free.lower_bound(idx);//searches for idx >= target/ideal idx
            if(it==currently_free.end()||((*it)>=idx+k)) return -1;
            return (*it)%k;
        };

        //Scheduler logic
        for(int i=0;i<n;i++){
            int curr_time=arrival[i];
            //free up completed
            while(!completion_times.empty() && completion_times.top().first<=curr_time){
                int completed_server=completion_times.top().second;
                toggle(completed_server,true);
                toggle(completed_server+k,true);
                completion_times.pop();
            }
            //assign the curr task in hand
            int ideal_server_to_assigned=i%k;
            int most_feasible_server_available_at_the_moment=leftmost_free_server(ideal_server_to_assigned);
            if(most_feasible_server_available_at_the_moment==-1) continue;//the request is dropped
            toggle(most_feasible_server_available_at_the_moment,false);
            toggle(most_feasible_server_available_at_the_moment+k,false);//toggle it's alias on as weell considering that 2k wrapping technique
            completion_times.push({curr_time+load[i],most_feasible_server_available_at_the_moment});
            num_times_assigned[most_feasible_server_available_at_the_moment].first++;
        }

        //Post analysis and result
        sort(num_times_assigned.begin(),num_times_assigned.end(),greater<pii>());
        int max_freq=num_times_assigned[0].first;
        vector<int>res;
        for(int i=0;i<k;i++){
            if(num_times_assigned[i].first==max_freq) res.push_back(num_times_assigned[i].second);
            else break;
        }
        return res;
    }
};