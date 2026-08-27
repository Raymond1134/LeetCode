from functools import cache

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:

        @cache
        def lis_ending_at(i):
            longest = 0

            for j in range(i):
                if nums[j] < nums[i]:
                    longest = max(longest, lis_ending_at(j))

            return longest + 1

        return max(lis_ending_at(i) for i in range(len(nums)))