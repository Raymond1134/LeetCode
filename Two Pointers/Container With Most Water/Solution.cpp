class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater = 0;
        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            maxWater = max(maxWater, min(heights[left], heights[right]) * (right - left));
            if (heights[left] < heights[right]) left++;
            else right--;
        }

        return maxWater;
    }
};
