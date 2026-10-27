class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size();

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[left] < nums[mid]) left = mid;
            else right = mid;
        }

        return left == nums.size() - 1 ? nums[0] : nums[left + 1];
    }
};
