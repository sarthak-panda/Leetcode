class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>>events;
        for(auto&log:logs){
            events.push_back({log[0],1});
            events.push_back({log[1],-1});
        }
        sort(events.begin(),events.end());
        int curr_pop=0,max_pop=0,min_year=2051;
        for(auto&e:events){
            curr_pop+=e.second;//this works bcs we are keeping track of max and in sort for a same yar, -1's appear first, else we would have needed to accumulate for each single year/event at once to avoid spikes
            if(curr_pop>max_pop) max_pop=curr_pop,min_year=e.first;
        }
        return min_year;
    }
};