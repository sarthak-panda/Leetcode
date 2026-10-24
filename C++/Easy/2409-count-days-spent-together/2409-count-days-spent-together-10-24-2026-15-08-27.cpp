class Solution {
public:
    inline static vector<int> monthToDays={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    inline static vector<int> cummDays={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    int covertToDayCount(const string&date){
        stringstream ss(date);
        int mm,dd; char delimiter;
        ss>>mm>>delimiter>>dd;
        return cummDays[mm-1]+(dd-1);//returns days which are completely over excluding current day, kind of 0 indexing
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int as=covertToDayCount(arriveAlice);
        int ae=covertToDayCount(leaveAlice);
        int bs=covertToDayCount(arriveBob);
        int be=covertToDayCount(leaveBob);
        cout<<as<<" "<<ae<<" "<<bs<<" "<<be<<endl;
        //think of intervals [as,ae], [bs,be]
        //sort it according to start times then [s1,e1],[s2,e2] 
        //then overlap happens when e1>=s2 and the no. of days
        // in overlap is min(e1,e2)-s2+1, if min(e1,e2)<s2 no overlap and we can return 0
        if(as<bs) return max(min(ae,be)-bs+1,0);
        else return max(min(be,ae)-as+1,0);
    }
};