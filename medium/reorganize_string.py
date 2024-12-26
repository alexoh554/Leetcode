# Solution could be faster 

class Solution:
    def reorganizeString(self, s: str) -> str:
        freq = {}

        for char in s:
            if char in freq:
                freq[char] += 1
            else:
                freq[char] = 1
        
        maxHeap = [[-value, key] for key,value in freq.items()]
        heapq.heapify(maxHeap)

        ans = ""
        while len(maxHeap) > 1:
            # Get top 2 characters
            char1 = heapq.heappop(maxHeap)
            char2 = heapq.heappop(maxHeap)
            
            ans += char1[1] + char2[1]

            char1[0] += 1
            char2[0] += 1

            heapq.heappush(maxHeap, char1) if char1[0] != 0 else None
            heapq.heappush(maxHeap, char2) if char2[0] != 0 else None

        if maxHeap:
            ans += heapq.heappop(maxHeap)[1]

        if len(ans) < len(s):
            return ""
            
        return ans

