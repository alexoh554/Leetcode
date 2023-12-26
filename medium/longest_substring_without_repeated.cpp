// Sliding window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        bool visited[256] = {false};
        int i = 0, j = 0;

        while (i < s.length() && j < s.length()) {
            if (visited[s[j]] == false) {
                visited[s[j]] = true;
                ++j;
                ans = max(ans, j - i);
            }
            else {
                visited[s[i]] = false;
                ++i;
            }
        }
        return ans;
    }
};