class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals, key = lambda x: x[0]) # O(nlogn)
        n = len(intervals)
        
        i = 1
        curInterval = intervals[0]
        result = []
        while i < len(intervals): # O(n)
            if intervals[i][0] < curInterval[1] and intervals[i][1] > curInterval[0]:
                curInterval[0] = max(curInterval[0], intervals[i][0])
                curInterval[1] = min(curInterval[1], intervals[i][1])
            else:
                result.append(curInterval)
                curInterval = intervals[i]
            
            i += 1
        
        result.append(curInterval)
        
        return n - len(result)