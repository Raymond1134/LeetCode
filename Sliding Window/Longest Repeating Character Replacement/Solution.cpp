class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> windowCharCounts;
        int result = 0;
        int left = 0, maxFreq = 0;

        for (int right = 0; right < s.size(); right++) {
            windowCharCounts[s[right]]++;
            maxFreq = max(maxFreq, windowCharCounts[s[right]]);

            while (right - left - maxFreq + 1 > k) {
                windowCharCounts[s[left]]--;
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};
