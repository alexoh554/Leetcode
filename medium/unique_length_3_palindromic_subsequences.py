# Time complexity: O(N^2)
# Space complexity: O(N)

# This solution could be optimized to O(N), O(1)

class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        found = set()
        firstAndLast = {}

        for i in range(len(s)):
            if s[i] in firstAndLast:
                firstAndLast[s[i]][1] = i
            else:
                o = [i, None]
                firstAndLast[s[i]] = o
        
        for char, occ in firstAndLast.items():
            left = occ[0]
            right = occ[1]

            if not right:
                continue

            for i in range(left + 1, right):
                word = char + s[i] + char
                found.add(word)
            
        return len(found)
