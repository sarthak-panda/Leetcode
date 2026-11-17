import math

class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        n = len(s)
        
        # 1. Precompute proper divisors for every length up to n
        divisors = [[] for _ in range(n + 1)]
        for i in range(1, n):
            for j in range(i * 2, n + 1, i):
                divisors[j].append(i)
                
        # 2. Precompute the minimum changes to make any s[i:j+1] a semi-palindrome
        cost = [[0] * n for _ in range(n)]
        
        for i in range(n):
            for j in range(i + 1, n):
                L = j - i + 1
                min_changes = math.inf
                
                # Try every proper divisor for length L
                for d in divisors[L]:
                    changes = 0
                    count = L // d
                    
                    # Verify the d groups
                    for c in range(d):
                        left = 0
                        right = count - 1
                        
                        # Check pairs moving towards the center of the group
                        while left < right:
                            if s[i + c + left * d] != s[i + c + right * d]:
                                changes += 1
                            left += 1
                            right -= 1
                            
                        # Early Break: Stop if we've already matched or exceeded the current best cost
                        if changes >= min_changes:
                            break
                            
                    if changes < min_changes:
                        min_changes = changes
                    
                    # Optimal escape: We cannot beat 0 changes
                    if min_changes == 0:
                        break
                        
                cost[i][j] = min_changes
                
        # 3. DP to partition the string into exactly k pieces
        # dp[i][p] stores the minimum changes for prefix s[0...i] using p partitions
        dp = [[math.inf] * (k + 1) for _ in range(n)]
        
        # Base Case: 1 partition spanning the prefix
        for i in range(1, n):
            dp[i][1] = cost[0][i]
            
        # Fill DP for 2 to k partitions
        for p in range(2, k + 1):
            # i must allow for at least p parts, each of length >= 2
            for i in range(p * 2 - 1, n):
                # m represents the end index of the previous (p-1) parts
                for m in range(2 * p - 3, i - 1):
                    if dp[m][p - 1] != math.inf:
                        if dp[m][p - 1] + cost[m + 1][i] < dp[i][p]:
                            dp[i][p] = dp[m][p - 1] + cost[m + 1][i]
                            
        return dp[n - 1][k]