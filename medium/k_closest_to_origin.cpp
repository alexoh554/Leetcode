// Minheap
#include <queue>

struct ComparePoints {
    bool operator()(const vector<int>& p1, const vector<int>& p2) {
        return (p1[0]*p1[0] + p1[1]*p1[1]) > (p2[0]*p2[0] + p2[1]*p2[1]);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, ComparePoints> pq;

        for (int i = 0; i < points.size(); i++) {
            pq.push(points[i]);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
