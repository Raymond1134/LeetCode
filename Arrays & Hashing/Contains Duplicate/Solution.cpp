class Solution {
    public:
        bool hasDuplicate(vector<int>& nums) {
            unordered_set<int> entries;
            for (int i : nums) {
                if (entries.find(i) != entries.end()) {
                    return true;
                }
                entries.insert(i);
            }
            return false;
        }
    };