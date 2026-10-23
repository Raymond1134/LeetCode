class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int, int>> dTemps;
        vector<int> results(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            int temp = temperatures[i];
            if (dTemps.empty() || temp <= dTemps.back().first) {
                dTemps.push_back({temp, i});
            }
            else {
                while (true) {
                    if (dTemps.size() == 0) break;
                    pair<int, int> tempEntry = dTemps.back();
                    if (temp <= tempEntry.first) break;
                    dTemps.pop_back();
                    results[tempEntry.second] = i - tempEntry.second;
                }
                dTemps.push_back(make_pair(temp, i));
            }
        }

        return results;
    }
};
