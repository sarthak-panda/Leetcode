class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)

        # Build original tree
        adj = [[] for _ in range(n)]
        for i in range(1, n):
            adj[parent[i]].append(i)

        # Stack of ancestors for each character
        char_stack = [[] for _ in range(26)]

        ans = [0] * n

        def dfs(u, p):
            ans[u] = 1

            c = ord(s[u]) - ord('a')
            char_stack[c].append(u)

            # Process children in original tree
            for v in adj[u]:
                dfs(v, u)

            # Find the new parent
            if len(char_stack[c]) > 1:
                new_parent = char_stack[c][-2]
            else:
                new_parent = p

            # Add current subtree size to its new parent
            if new_parent != -1:
                ans[new_parent] += ans[u]

            char_stack[c].pop()

        dfs(0, -1)

        return ans