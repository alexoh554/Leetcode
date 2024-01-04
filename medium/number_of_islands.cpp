#include <stack>
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int max_x = grid.size();
        int max_y = grid[0].size();
        int ans = 0;

        std::vector<std::vector<bool>> visited(max_x, std::vector<bool>(max_y, false));
        std::stack<std::pair<int, int>> s;

        for (int i = 0; i < max_x; ++i) {
            for (int j = 0; j < max_y; ++j) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    s.push({i, j});
                    ++ans;

                    while (!s.empty()) {
                        auto cur = s.top();
                        s.pop();
                        int a = cur.first;
                        int b = cur.second;

                        visited[a][b] = true;

                        if (a + 1 < max_x) { 
                            if (grid[a + 1][b] == '1' && visited[a+1][b] == false) {
                                s.push({a + 1, b});
                                visited[a + 1][b] = true;
                            }
                        }
                        if (a - 1 >= 0) {
                            if (grid[a - 1][b] == '1' && visited[a - 1][b] == false) {
                                s.push({a-1, b});
                                visited[a-1][b] = true;
                            }
                        }
                        if (b - 1 >= 0) {
                            if (grid[a][b-1] == '1' && visited[a][b-1] == false) {
                                s.push({a, b-1});
                                visited[a][b-1] = true;
                            }
                        }  
                        if (b + 1 < max_y) {
                            if (grid[a][b + 1] == '1' && visited[a][b + 1] == false) {
                                s.push({a, b + 1});
                                visited[a][b + 1] = true;
                            }
                        }   
                    }
                }
            }
        }

        return ans;
    }
};
