class Solution {
private:
    static constexpr int LOG = 17;

    vector<vector<int>> adj;
    vector<array<int, LOG>> up;

    vector<int> depth, tin, tout, prefix;
    int timer = 0;

    // Fenwick Tree supporting XOR updates and prefix XOR queries
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void update(int idx, int val) {
            for (int i = idx + 1; i <= n; i += i & -i) {
                bit[i] ^= val;
            }
        }

        int query(int idx) {
            int res = 0;

            for (int i = idx + 1; i > 0; i -= i & -i) {
                res ^= bit[i];
            }

            return res;
        }
    };

    int getMask(char c) {
        return 1 << (c - 'a');
    }

    // Iterative DFS to avoid stack overflow on a chain-shaped tree
    void dfs(int root, const string& s) {
        // {node, parent, exiting}
        vector<tuple<int, int, bool>> st;
        st.emplace_back(root, -1, false);

        while (!st.empty()) {
            auto [u, par, exiting] = st.back();
            st.pop_back();

            if (exiting) {
                tout[u] = timer;
                continue;
            }

            tin[u] = timer++;

            up[u][0] = par;

            for (int j = 1; j < LOG; j++) {
                int mid = up[u][j - 1];

                up[u][j] = (mid == -1)
                               ? -1
                               : up[mid][j - 1];
            }

            depth[u] = (par == -1) ? 0 : depth[par] + 1;

            prefix[u] = getMask(s[u]);

            if (par != -1) {
                prefix[u] ^= prefix[par];
            }

            // Process the exit event after all children.
            st.emplace_back(u, par, true);

            for (auto it = adj[u].rbegin();
                 it != adj[u].rend(); ++it) {
                if (*it != par) {
                    st.emplace_back(*it, u, false);
                }
            }
        }
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) {
            swap(a, b);
        }

        int diff = depth[a] - depth[b];

        for (int j = 0; j < LOG; j++) {
            if ((diff >> j) & 1) {
                a = up[a][j];
            }
        }

        if (a == b) {
            return a;
        }

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});
        up.resize(n);

        for (auto& row : up) {
            row.fill(-1);
        }

        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        prefix.assign(n, 0);
        timer = 0;

        // Build the tree.
        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, s);

        Fenwick bit(n);

        // Store references to the input without making copies.
        [[maybe_unused]] auto suneravilo =
            std::tie(n, edges, s, queries);

        vector<bool> ans;

        for (const string& q : queries) {
            string op;
            int u, v;

            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                // Difference between the old and new characters.
                int delta = getMask(s[u]) ^ getMask(c);

                if (delta != 0) {
                    // Every node in u's subtree has its root-prefix
                    // mask changed by delta.
                    bit.update(tin[u], delta);
                    bit.update(tout[u], delta);
                }

                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);

                // Current root-to-node prefix masks.
                int pu = prefix[u] ^ bit.query(tin[u]);
                int pv = prefix[v] ^ bit.query(tin[v]);

                // XOR mask of characters on the u-to-v path.
                int mask = pu ^ pv ^ getMask(s[w]);

                // At most one character may have odd frequency.
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};