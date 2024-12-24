class Solution(object):
    def computeOnes(self, n):
        ones = 0
        while n != 0:
            ones += n % 2
            n >>= 1
        return ones
        
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        arr = []
        for i in range(n + 1):
            arr.append(self.computeOnes(i))

        return arr
