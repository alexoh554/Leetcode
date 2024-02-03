class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        return func(nums, l, r, target);
    }

    int func(vector<int>& nums, int l, int r, int t) {
        int m = (l + r) / 2;
        if (nums[m] == t) {
            return m;
        }
        else if (l > r) {
            return -1;
        }

        if (nums[l] <= nums[m]) {
            // Left half is sorted
            if (nums[l] <= t && t < nums[m]) {
                return func(nums, l, m - 1, t);
            } else {
                return func(nums, m + 1, r, t);
            }
        } else {
            // Right half is sorted
            if (nums[m] < t && t <= nums[r]) {
                return func(nums, m + 1, r, t);
            } else {
                return func(nums, l, m - 1, t);
            }
        }
    }
};

