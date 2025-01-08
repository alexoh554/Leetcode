class Solution:
    def isPrefixAndSuffix(self, w1, w2):
        return w2.startswith(w1) and w2.endswith(w1)

    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        count = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if self.isPrefixAndSuffix(words[i], words[j]):
                    count += 1

        return count