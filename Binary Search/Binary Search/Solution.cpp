class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size() - 1;
        int cur;
        while (lower <= upper) {
            cur = (lower + upper) / 2;
            if (nums[cur] == target) {
                return cur;
            }
            else if (target > nums[cur]) {
                lower = cur + 1;
            }
            else {
                upper = cur - 1;
            }
        }
        return -1;
    }
};
