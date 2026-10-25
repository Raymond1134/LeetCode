class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        
        for (int i = 0; i < position.size(); i++) {
            cars.emplace_back(pair<int, int>{position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        double slowestFleet = -1;
        int fleetCounter = 0;

        for (int i = 0; i < cars.size(); i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;
            if (time > slowestFleet) {
                slowestFleet = time;
                fleetCounter++;
            }
        }

        return fleetCounter;
    }
};
