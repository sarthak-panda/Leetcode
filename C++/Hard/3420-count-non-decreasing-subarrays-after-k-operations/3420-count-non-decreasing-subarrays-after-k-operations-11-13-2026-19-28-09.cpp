class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Next strictly greater element to the right
        vector<int> nge(n);
        vector<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] <= nums[i])
                st.pop_back();

            nge[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }

        // Prefix sums of nums
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        // Binary lifting
        int LOG = 1;
        while ((1LL << LOG) <= n) LOG++;

        vector<vector<int>> jump(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> sum(LOG, vector<long long>(n + 1, 0));

        // Base case: one segment [i, nge[i] - 1]
        for (int i = 0; i < n; i++) {
            jump[0][i] = nge[i];
            sum[0][i] = 1LL * nums[i] * (nge[i] - i);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int mid = jump[j - 1][i];

                jump[j][i] = jump[j - 1][mid];
                sum[j][i] = sum[j - 1][i] + sum[j - 1][mid];
            }
        }

        // Minimum operations required for subarray [l, r]
        auto getCost = [&](int l, int r) -> long long {
            long long mxSum = 0;
            int cur = l;

            // Consume complete prefix-maximum segments
            for (int j = LOG - 1; j >= 0; j--) {
                if (jump[j][cur] <= r) {
                    mxSum += sum[j][cur];
                    cur = jump[j][cur];
                }
            }

            // Last partially covered segment
            mxSum += 1LL * nums[cur] * (r - cur + 1);

            // Sum(prefix maximum - original element)
            return mxSum - (pref[r + 1] - pref[l]);
        };

        // Sliding window
        long long ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            while (getCost(l, r) > k)
                l++;

            ans += r - l + 1;
        }

        return ans;
    }
};