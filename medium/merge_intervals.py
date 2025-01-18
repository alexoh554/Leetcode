class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return None
        sortedIntervals = sorted(intervals, key=lambda x: x[0])
        
        result = []
        
        curInterval = sortedIntervals[0]
        i = 1
        while i < len(intervals):
            if sortedIntervals[i][0] <= curInterval[1]:
                curInterval[1] = max(curInterval[1], sortedIntervals[i][1])
            else:
                result.append(curInterval)
                curInterval = sortedIntervals[i]
            i += 1
        result.append(curInterval)
        return result