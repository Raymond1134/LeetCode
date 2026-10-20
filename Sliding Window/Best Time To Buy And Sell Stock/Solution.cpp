class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = *max_element(prices.begin(), prices.end());
        int highestProfit = 0;
        for (int i : prices) {
            lowest = min(lowest, i);
            highestProfit = max(highestProfit, i - lowest);
        }
        return highestProfit;
    }
};
