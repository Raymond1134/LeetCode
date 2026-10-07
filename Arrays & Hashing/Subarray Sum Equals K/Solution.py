class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        psc_dict = {0: 1}
        running_sum = 0
        counter = 0

        for num in nums:
            running_sum += num
            counter += psc_dict.get(running_sum - k, 0)
            psc_dict[running_sum] = psc_dict.get(running_sum, 0) + 1

        return counter