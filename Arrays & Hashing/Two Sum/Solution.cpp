class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> numbers;
            for (int i = 0; i < nums.size(); i++) {
                int wanted = target - nums[i];
                if (numbers.find(wanted) != numbers.end()) {
                    return vector<int>{numbers[wanted], i};
                }
                else {
                    numbers[nums[i]] = i;
                }
            }
            return vector<int>(0);
        }
    };