// Review this one
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        func(nums, 0, n - 1, ans);

        return ans;
    }

    void func(vector<int>& nums, int l, int r, vector<vector<int>>& ans) {
        if (l == r) {
            ans.push_back(nums);
            return;
        }

        for (int i = l; i <= r; i++) {
            swap(nums[l], nums[i]);
            
            func(nums, l + 1, r, ans);

            // Backtrack
            swap(nums[l], nums[i]);
        }
    }
};
