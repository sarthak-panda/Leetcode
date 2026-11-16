class Solution {
public:
    string digitSum(string s, int k) {
        string c=s,nxt="";
        while(c.size()>k){
            int N=c.size();
            for(int i=0;i<N;i+=k){
                int sum=0;
                for(int j=i;j<min(i+k,N);j++){
                    sum+=(c[j]-'0');
                }
                nxt.append(to_string(sum));
            }
            c=nxt;
            nxt="";
        }
        return c;
    }
};