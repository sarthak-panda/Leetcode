class Solution:
    def gcd(self,a,b):
        while b:
            a,b=b,a%b
        return a
    def lcm(self,a,b):
        return (a*b)//(self.gcd(a,b))
    def array_gcd(self,arr):
        result=arr[0]
        for i in range(1,len(arr)):
            result=self.gcd(result,arr[i])
        return result
    def array_lcm(self,arr):
        result=arr[0]
        for i in range(1,len(arr)):
            result=self.lcm(result,arr[i])
        return result
    def array_product(self,arr):
        result=1
        for a in arr:
            result*=a
        return result
    def is_prod_eq(self,arr):
        prod=self.array_product(arr)
        g=self.array_gcd(arr)
        l=self.array_lcm(arr)
        return (prod==(g*l))
    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)
        max_length = 0
        for start in range(n):
            current_array = []
            for end in range(start, n):
                current_array.append(nums[end])
                if self.is_prod_eq(current_array):
                    max_length = max(max_length, end - start + 1)
        
        return max_length        