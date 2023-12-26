// BAD BFS Solution

#include <queue>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<int>> ans(m, std::vector<int>(n, 0));
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                    visited[i][j] = true;
                }
                else {
                    ans[i][j] = 1000000;
                }
            }
        }

        while (!q.empty()) {
            std::pair<int, int> cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            for (int i = -1; i <= 1; i+=2) {
                if (x + i < 0 || x + i >= m || visited[x + i][y] == true) {
                    continue;
                }
                ans[x + i][y] = min(ans[x][y] + 1, ans[x + i][y]);
                visited[x + i][y] = true;
                q.push({x + i, y});
            }
            for (int j = -1; j <= 1; j+=2) {
                if (y + j < 0 || y + j >= n || visited[x][y + j] == true) {
                    continue;
                }
                ans[x][y + j] = min(ans[x][y] + 1, ans[x][y + j]);
                visited[x][y + j] = true;
                q.push({x, y + j});
            }
        }

        return ans;
    }
};
