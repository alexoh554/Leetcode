#include <vector>
#include <algorithm>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        vector<int> arr(amount + 1, INT_MAX - 1);

        arr[0] = 0;

        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <= amount; ++j) {
                arr[j] = min(arr[j], arr[j - coins[i]] + 1);
            }
        }

        return (arr[amount] == INT_MAX - 1) ? -1 : arr[amount];a
    }
};
