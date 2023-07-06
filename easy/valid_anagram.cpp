// Count using an array where each element is one letter

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_count[26]{0};
        int t_count[26]{0};

        for (int i = 0; i < s.length(); ++i) {
            ++s_count[s[i] % 26];
        }
        for (int i = 0; i < t.length(); ++i) {
            ++t_count[t[i] % 26];
        }
        for (int i = 0; i < 26; ++i) {
            if (s_count[i] != t_count[i]) {
                return false;
            }
        }
        return true;
    }
};