class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        currentLongest = 0

        for i in nums:
            if (i - 1) in nums:
                continue
            
            k = i
            counter = 0
            while k in nums:
                k += 1
                counter += 1
            
            currentLongest = max(currentLongest, counter)
        
        return currentLongest
