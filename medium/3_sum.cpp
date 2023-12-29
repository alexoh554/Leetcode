#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> ans;

        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1;
            int r = nums.size() - 1;

            int target = 0 - nums[i];
            while (l < r) {
                int cur = nums[l] + nums[r];

                if (cur == target) {
                    ans.push_back({ nums[i], nums[l], nums[r] });

                    // Skip duplicates
                    while (l < r && nums[l] == nums[l + 1]) {
                        ++l;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        --r;
                    }

                    // Move pointers
                    ++l;
                    --r;
                } else if (cur > target) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return ans;
    }
};
