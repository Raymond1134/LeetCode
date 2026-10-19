class Solution:
    def trap(self, height: list[int]) -> int:
        left = 0
        right = len(height) - 1
        currWaterHeight = min(height[left], height[right])
        totalWater = currWaterHeight * max(right - left - 1, 0)

        while left < right:
            if height[right] < height[left]:
                right -= 1
                if left == right: return totalWater
                totalWater -= min(currWaterHeight, height[right])
            else:
                left += 1
                if left == right: return totalWater
                totalWater -= min(currWaterHeight, height[left])
            
            newWaterHeight = min(height[left], height[right])

            if newWaterHeight > currWaterHeight:
                totalWater += (newWaterHeight - currWaterHeight) * max(right - left - 1, 0)
                currWaterHeight = newWaterHeight
        
        return totalWater