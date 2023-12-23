class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> new_int;
        int i = 0;

        while (i < intervals.size() && newInterval[0] > intervals[i][1]) {
            new_int.push_back(intervals[i]);
            i++;
        }

        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        new_int.push_back({newInterval[0], newInterval[1]});

        while (i < intervals.size()) {
            new_int.push_back(intervals[i]);
            i++;
        }

        return new_int;
    }
};
