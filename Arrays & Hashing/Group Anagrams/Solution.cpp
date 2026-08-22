class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> groups;
    
            for (string s : strs) {
                vector<int> count(26, 0);
    
                for (char c : s) {
                    count[c - 'a']++;
                }
    
                string key;
    
                for (int x : count) {
                    key += '#' + to_string(x);
                }
    
                groups[key].emplace_back(s);
            }
    
            vector<vector<string>> result;
    
            for (auto& [key, group] : groups) {
                result.emplace_back(group);
            }
    
            return result;
        }
    };