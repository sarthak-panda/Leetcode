class Solution {
    double fastPow(double x, long long n) {
        if (n == 0)
            return 1.0;

        double half = fastPow(x, n / 2);
        double res = half * half;

        if (n % 2 == 1)
            res *= x;

        return res;
    }

public:
    double myPow(double x, int n) {
        long long exp = n;

        if (exp < 0) {
            exp = -exp;
        }
        double r=fastPow(x, exp);
        return (n>=0)?r:(1.0/r);
    }
};