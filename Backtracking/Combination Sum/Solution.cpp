class Solution {
    vector<vector<int>> result;

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end(), std::greater<>());
        computeResults(vector<int>(), 0, nums, target, 0);
        return result;
    }

    void computeResults(vector<int> attempt, int currentTotal, vector<int>& nums, int target, int curIdx) {
        if (currentTotal == target) {
            result.push_back(attempt);
            return;
        }
        else if (currentTotal > target) return;
        else {
            for (int i = curIdx; i < nums.size(); i++) {
                attempt.push_back(nums[i]);
                computeResults(attempt, currentTotal + nums[i], nums, target, i);
                attempt.pop_back();
            }
        }
    }
};
