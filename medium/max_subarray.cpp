// DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> max_nums(nums.size());
        max_nums[0] = nums[0]; 
        int max_sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            max_nums[i] = max(max_nums[i - 1] + nums[i], nums[i]);
            if (max_sum < max_nums[i]) {
                max_sum = max_nums[i];
            }
        }

        return max_sum;
    }
};