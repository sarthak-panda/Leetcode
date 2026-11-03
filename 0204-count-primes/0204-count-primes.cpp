const int N=5000000;
int Prime[N+1];
static bool intialized=false;
class Solution {
public:
    int countPrimes(int n) {
        if(!intialized){
            intialized=true;
            fill(Prime,Prime+N+1,1);
            for(int i=2;i*i<=N;i++){
                if(Prime[i]){
                    for(int j=i*i;j<=N;j+=i){
                        Prime[j]=0;
                    }
                }
            }
            //compute prefix
            int cnt=0,temp;
            for(int i=2;i<=N;i++){
                temp=Prime[i];
                Prime[i]=cnt;
                cnt+=temp;
            }
            Prime[1]=Prime[0]=0;
        }
        return Prime[n];
    }
};