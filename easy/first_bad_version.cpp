// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// fastest method: binary search

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        int mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (isBadVersion(mid) == false) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};