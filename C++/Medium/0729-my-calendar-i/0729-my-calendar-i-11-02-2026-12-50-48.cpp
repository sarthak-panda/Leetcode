class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]+=1;
        mp[endTime]-=1;
        int count=0;
        for(auto&it:mp){
            count+=it.second;
            if(count>=2){
                mp[endTime]+=1;
                mp[startTime]-=1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */