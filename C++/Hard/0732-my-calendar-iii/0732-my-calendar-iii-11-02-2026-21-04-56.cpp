class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]+=1;
        mp[endTime]-=1;
        int count=0,maxcnt=0;
        for(auto&it:mp){
            count+=it.second;
            maxcnt=max(maxcnt,count);
        }
        return maxcnt;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */