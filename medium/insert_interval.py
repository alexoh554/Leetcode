class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if len(intervals) == 0:
            return [newInterval]

        i = 0

        newArr = []

        newStart = newInterval[0]
        newEnd = newInterval[1]
        
        # Insert normally, no merge
        while i < len(intervals) and intervals[i][1] < newStart:
            newArr.append(intervals[i])
            i += 1

        # Overlapping times, need to merge
        while i < len(intervals) and newEnd >= intervals[i][0]:
            newStart = min(newStart, intervals[i][0])
            newEnd = max(newEnd, intervals[i][1])
            i += 1
        
        newArr.append([newStart, newEnd])

        # No merge needed anymore
        while i < len(intervals):
            newArr.append(intervals[i])
            i += 1

        return newArr



        