// Look for cycles in graph
// Passes 45/52

#include <stack>
#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        if (n == 0) {
            return true;
        }
        int dict[2000][2000] = {0};

        int state[2000] = {0}; // 0 = not visited, 1 = visiting, 2 = visited

        for (int i = 0; i < n; i++) {
            dict[prerequisites[i][1]][prerequisites[i][0]] = 1;
        }

        // DFS
        stack<int> s;
        int cur = prerequisites[0][1];
        s.push(cur);
        state[cur] = 1;
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            state[cur] = 1;
            for (int i = 0; i < 2000; i++) {
                if (dict[cur][i] == 1) {
                    s.push(i);
                    if (state[i] == 1) {
                        return false;
                    }
                    state[i] = 2;
                }
            }

        }

        return true;
    }
};