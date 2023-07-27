// dynamic programming
// to reach step i, add up the number of ways to reach step i-1 and i-2

class Solution {
public:
    int climbStairs(int n) {
        vector<int> stairs(n + 1);
        stairs[0] = 1;
        stairs[1] = 1;

        for (int i = 2; i <= n; i++) {
            stairs[i] = stairs[i - 1] + stairs[i - 2];
        }

         return stairs[n];
        
    }
};