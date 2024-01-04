#include <queue>

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int max = 0;
        int cur = 0;

        // Track the number of remaining fresh oranges
        int freshCount = 0;  

        int max_x = grid.size();
        int max_y = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < max_x; i++) {
            for (int j = 0; j < max_y; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) {
            return 0;  
        }

        while (!q.empty()) {
            int size = q.size();  
            cur++;

            for (int k = 0; k < size; k++) {
                pair<int, int> p = q.front();
                int x = p.first;
                int y = p.second;
                q.pop();

                if (x + 1 < max_x && grid[x + 1][y] == 1) {
                    q.push({x + 1, y});
                    grid[x + 1][y] = 2;
                    freshCount--;
                }
                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    q.push({x - 1, y});
                    grid[x - 1][y] = 2;
                    freshCount--;
                }
                if (y + 1 < max_y && grid[x][y + 1] == 1) {
                    q.push({x, y + 1});
                    grid[x][y + 1] = 2;
                    freshCount--;
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    q.push({x, y - 1});
                    grid[x][y - 1] = 2;
                    freshCount--;
                }
            }

            if (freshCount == 0) {
                return cur;
            }
        }

        return freshCount == 0 ? max : -1;  
    }
};
