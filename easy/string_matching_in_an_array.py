class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        sortedStrings = sorted(words, key = len)
        result = set()

        for i in range(len(sortedStrings)):
            word = sortedStrings[i]
            for j in range(i + 1, len(sortedStrings)):
                if word in sortedStrings[j]:
                    result.add(word)
                    break

        return list(result)
            