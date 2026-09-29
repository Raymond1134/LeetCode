class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        vector<vector <int>> buckets(nums.size() + 1);
        vector<int> results(k);

        for (int num : nums) freqs[num]++;
        for (auto &[num, count] : freqs) buckets[count].push_back(num);

        int counter = 0;

        for (int i = nums.size(); counter != k; i--) {
            for (int n : buckets[i]) {
                results[counter] = n;
                counter++;
            }
        }

        return results;
    }
};
