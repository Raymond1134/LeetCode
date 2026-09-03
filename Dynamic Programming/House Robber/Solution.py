from functools import cache

class Solution:
    def rob(self, nums: List[int]) -> int:

        @cache
        def search(i):
            if i >= len(nums): return 0
            return max(search(i + 1), nums[i] + search(i + 2))
        
        return search(0)