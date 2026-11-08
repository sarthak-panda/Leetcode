class Solution {
    using ll = long long;
    using ull = unsigned int;

    // Minimum increment required to make all target bits set.
    static ll cost(ull x, ull target) {
        ull missing = target & ~x;

        if (missing == 0) return 0;

        // Highest bit that is missing in x.
        int p = 31 - __builtin_clz(missing);

        ll mask = (1LL << p) - 1;

        return (1LL << p)
             + (static_cast<ll>(target) & mask)
             - (static_cast<ll>(x) & mask);
    }

public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int n = nums.size();
        vector<ll> costs(n);

        ull ans = 0;

        for (int bit = 30; bit >= 0; --bit) {
            ull candidate = ans | (1U << bit);

            for (int j = 0; j < n; ++j) {
                costs[j] = cost(nums[j], candidate);
            }

            // Select the m smallest costs.
            nth_element(costs.begin(),
                        costs.begin() + m - 1,
                        costs.end());

            // Sum with early termination.
            ll total = 0;

            for (int j = 0; j < m; ++j) {
                total += costs[j];
                if (total > k) break;
            }

            if (total <= k) {
                ans = candidate;
            }
        }

        return static_cast<int>(ans);
    }
};