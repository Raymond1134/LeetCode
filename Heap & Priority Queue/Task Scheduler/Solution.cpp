class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int taskFrequencies[26] = {0};
        int maxFrequency = 0;
        int maxCount = 0;

        for (char task : tasks) ++taskFrequencies[task - 'A'];
        for (int frequency : taskFrequencies) maxFrequency = max(maxFrequency, frequency);
        for (int frequency : taskFrequencies) if (frequency == maxFrequency) ++maxCount;

        return max((int)tasks.size(), (maxFrequency - 1) * (n + 1) + maxCount);
    }
};