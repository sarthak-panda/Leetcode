class Solution {
public:
    int minOperations(string s) {
        string sorted_s=s; int n=s.size();
        sort(sorted_s.begin(),sorted_s.end());
        if(sorted_s==s) return 0;
        else if(sorted_s[0]==s[0]||sorted_s[n-1]==s[n-1]) return 1;
        else{
            //both lowest and high orders must be freq 1
            // and at oppsite poles to be 3 steped
            char lowest_char='z'+1, highest_char='a'-1;
            int count_of_lowest_char=0,count_of_highest_char=0;
            for(auto&c:s){
                if(c<lowest_char) count_of_lowest_char=1,lowest_char=c;
                else if(c==lowest_char) count_of_lowest_char++;

                if(c>highest_char) count_of_highest_char=1,highest_char=c;
                else if(c==highest_char) count_of_highest_char++;
            }
            if(count_of_highest_char==1 && count_of_lowest_char==1 && s[0]==highest_char && s[n-1]==lowest_char){
                if(n==2) return -1;
                else return 3;
            }
        }
        return 2;
    }
};