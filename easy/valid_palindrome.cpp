#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0; 
        int r = s.size() - 1;

        while(l <= r) {
            if (tolower(s[l]) < 'a' || tolower(s[l]) > 'z') {
                ++l;
                continue;
            }
            if (tolower(s[r]) < 'a' || tolower(s[r]) > 'z') {
                --r;
                continue;
            }

            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            ++l;
            --r;
        }

        return true;
    }
};