class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '1') {
                    islands++;
                    vector<pair<int, int>> toBeVisited;
                    toBeVisited.emplace_back(row, col);

                    while (toBeVisited.size() > 0) {
                        pair<int, int> cur = toBeVisited.back();
                        toBeVisited.pop_back();

                        if (cur.first > 0 && grid[cur.first - 1][cur.second] == '1') toBeVisited.emplace_back(cur.first - 1, cur.second);
                        if (cur.second > 0 && grid[cur.first][cur.second - 1] == '1') toBeVisited.emplace_back(cur.first, cur.second - 1);
                        if (cur.first + 1 < rows && grid[cur.first + 1][cur.second] == '1') toBeVisited.emplace_back(cur.first + 1, cur.second);
                        if (cur.second + 1 < cols && grid[cur.first][cur.second + 1] == '1') toBeVisited.emplace_back(cur.first, cur.second + 1);

                        grid[cur.first][cur.second] = '0';
                    }
                }
            }
        }

        return islands;
    }
};
