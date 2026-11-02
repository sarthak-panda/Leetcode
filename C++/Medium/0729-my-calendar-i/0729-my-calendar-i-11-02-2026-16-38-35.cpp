class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto it=st.lower_bound({startTime,endTime});
        // SEE IF IT OVERLAPS WITH THE JUST NEXT
        if(it!=st.end() && it->first<endTime){
            return false;
        }
        // SEE IF IT OVERLAPS WITH JUST PREVIOUS
        if(it!=st.begin() && prev(it)->second>startTime){
            return false;
        }
        // NO ISSUES ISSUES INSERT IT SAFELY
        st.insert({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */