class Solution:
    def shiftChar(self, c, incr):
        newChar = ((ord(c) - 97 + incr) % 26) + 97        
        return chr(newChar)

    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        shiftCount = [0] * (len(s) + 1)

        for start, end, direction in shifts:
            if direction == 0:
                shiftCount[start] -= 1
                shiftCount[end + 1] += 1
            else:
                shiftCount[start] += 1
                shiftCount[end + 1] -= 1
        
        for i in range(1, len(shiftCount)):
            shiftCount[i] += shiftCount[i - 1]

        newString = ""
        for i in range(len(s)):
            newString += self.shiftChar(s[i], shiftCount[i])

        return newString