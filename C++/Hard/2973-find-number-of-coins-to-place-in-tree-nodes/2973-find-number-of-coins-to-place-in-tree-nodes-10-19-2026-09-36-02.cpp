class Solution {
    using ll = long long;

    struct Info {
        int sz = 0;
        int pc = 0, nc = 0;
        array<int, 3> pos{};  // Descending: largest 3 positives
        array<int, 2> neg{};  // Ascending: smallest 2 negatives
    };

    static void addPos(Info& a, int x) {
        if (a.pc == 3 && x <= a.pos[2]) return;

        int i = min(a.pc, 2);
        if (a.pc < 3) ++a.pc;

        while (i > 0 && a.pos[i - 1] < x) {
            a.pos[i] = a.pos[i - 1];
            --i;
        }
        a.pos[i] = x;
    }

    static void addNeg(Info& a, int x) {
        if (a.nc == 2 && x >= a.neg[1]) return;

        int i = min(a.nc, 1);
        if (a.nc < 2) ++a.nc;

        while (i > 0 && a.neg[i - 1] > x) {
            a.neg[i] = a.neg[i - 1];
            --i;
        }
        a.neg[i] = x;
    }

    Info solve(int u, int par,
               const vector<vector<int>>& adj,
               const vector<int>& cost,
               vector<ll>& ans) {
        Info cur;
        cur.sz = 1;

        if (cost[u] > 0) addPos(cur, cost[u]);
        else if (cost[u] < 0) addNeg(cur, cost[u]);

        for (int v : adj[u]) {
            if (v == par) continue;

            Info child = solve(v, u, adj, cost, ans);
            cur.sz += child.sz;

            for (int k = 0; k < child.pc; ++k)
                addPos(cur, child.pos[k]);

            for (int k = 0; k < child.nc; ++k)
                addNeg(cur, child.neg[k]);
        }

        if (cur.sz < 3) {
            ans[u] = 1;
        } else {
            ll p1 = (cur.pc == 3)
                ? 1LL * cur.pos[0] * cur.pos[1] * cur.pos[2]
                : 0LL;

            ll p2 = (cur.pc >= 1 && cur.nc == 2)
                ? 1LL * cur.pos[0] * cur.neg[0] * cur.neg[1]
                : 0LL;

            ans[u] = max({0LL, p1, p2});
        }

        return cur;
    }

public:
    vector<long long> placedCoins(vector<vector<int>>& edges,
                                  vector<int>& cost) {
        int n = cost.size();

        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<ll> ans(n);
        solve(0, -1, adj, cost, ans);

        return ans;
    }
};