# Prefix Sum
# Time complexity: O(n)
# Space complexity: O(n)  <-- O(n) due to the slice 

class Solution:
    def computeScore(self, left, right):
        score = 0
        for l in left:
            if l == '0':
                score += 1
        for r in right:
            if r == '1':
                score += 1
        return score

    def maxScore(self, s: str) -> int:
        # Divide at first element
        score = self.computeScore(s[0], s[1:])
        maxScore = score

        for c in s[1:len(s) - 1]:
            if c == '0':
                score += 1
            else:
                score -= 1
            
            maxScore = max(score, maxScore)
        return maxScore 
