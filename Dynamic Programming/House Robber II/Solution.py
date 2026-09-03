class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        
        arr1, arr2 = nums[:-1], nums[1:]

        def search(arr, i, memo):
            if i >= len(arr): return 0
            if i in memo: return memo[i]
            memo[i] = max(search(arr, i + 1, memo), arr[i] + search(arr, i + 2, memo))
            return memo[i]
        
        return max(search(arr1, 0, dict()), search(arr2, 0, dict()))