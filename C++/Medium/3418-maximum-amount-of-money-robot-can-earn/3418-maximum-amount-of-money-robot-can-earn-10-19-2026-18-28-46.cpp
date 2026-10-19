class Solution {
public:
    static constexpr int NEG = -1e9;
    int t[501][501][3];

    int solve(int i, int j, int k, int n, int m,
              const vector<vector<int>>& coins) {
        if (i >= n || j >= m) return NEG;

        if (i == n-1 && j == m-1)
            return (coins[i][j] < 0 && k > 0) ? 0 : coins[i][j];

        int& ans = t[i][j][k];
        if (ans != INT_MIN) return ans;

        ans = coins[i][j] + max(
            solve(i+1, j, k, n, m, coins),
            solve(i, j+1, k, n, m, coins)
        );

        if (coins[i][j] < 0 && k > 0) {
            ans = max(ans, max(
                solve(i+1, j, k-1, n, m, coins),
                solve(i, j+1, k-1, n, m, coins)
            ));
        }

        return ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();

        fill(&t[0][0][0], &t[0][0][0] + sizeof(t)/sizeof(int), INT_MIN);

        return solve(0, 0, 2, n, m, coins);
    }
};