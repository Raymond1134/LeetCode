class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int lVal = nums[left];
                int rVal = nums[right];
                int sum = nums[i] + lVal + rVal;

                if (sum < 0) {
                    while (left < right && nums[left] == lVal) ++left;
                }
                else if (sum > 0) {
                    while (left < right && nums[right] == rVal) --right;
                }
                else {
                    triplets.emplace_back(vector<int>{nums[i], lVal, rVal});
                    while (left < right && nums[left] == lVal && nums[right] == rVal) {
                        ++left;
                        --right;
                    }
                }
            }
        }

        return triplets;
    }
};
