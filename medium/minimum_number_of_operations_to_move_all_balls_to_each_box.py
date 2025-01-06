# Forward loop and backward loop which is optimal over nested loops

class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        n = len(boxes)
        ans = [0] * n

        numOperations = 0
        numBalls = 0
        for i in range(n):
            ans[i] += numOperations
            if boxes[i] == '1':
                numBalls += 1
            numOperations += numBalls

        numOperations = 0
        numBalls = 0
        for i in range(n - 1, -1, -1):
            ans[i] += numOperations
            if boxes[i] == '1':
                numBalls += 1
            numOperations += numBalls
        
        return ans