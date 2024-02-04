class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(candidates, target, 0, temp, ans);
        return ans;
    }

    void combinationSumHelper(vector<int>& candidates, int target, int start, vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
            temp.push_back(candidates[i]);
            combinationSumHelper(candidates, target - candidates[i], i, temp, ans);
            temp.pop_back();
        }
    }
};
