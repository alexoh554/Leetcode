// Create an array to tally instances of each letter

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letters[26] = { 0 };
        for (int i = 0; i < magazine.length(); ++i) {
            ++letters[magazine[i] % 97];
        }

        for (int i = 0; i < ransomNote.length(); ++i) {
            letters[ransomNote[i] % 97] -= 1;
            if (letters[ransomNote[i] % 97] < 0) {
                return false;
            }
        }

        return true;
    }
};