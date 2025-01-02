# Prefix sum approach
# Time complexity: O(n + q) where n = words.length, q = querys.length
# Space complexity: O(n) where n = words.length

class Solution:
    def startsAndEndsWithVowel(self, word):
        vowels = ['a', 'e', 'i', 'o', 'u']
        return int(word[0] in vowels and word[-1] in vowels)

    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        ans = []
        prefixSum = [0 for i in range(len(words))]
        prefixSum[0] = self.startsAndEndsWithVowel(words[0])

        for i in range(1, len(words)):
            prefixSum[i] = prefixSum[i - 1] + self.startsAndEndsWithVowel(words[i])

        for query in queries:
            l = query[0]
            r = query[1]
            if l == 0:
                ans.append(prefixSum[r])
            else:
                ans.append(prefixSum[r] - prefixSum[l - 1])
        return ans