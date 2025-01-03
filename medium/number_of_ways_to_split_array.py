# Time Complexity: O(n + n) = O(n)
# Space copmlexity: O(1)

class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        # Start at index 0
        i = 1
        left = nums[0]
        right = sum(nums[i:])

        ans = 0
        while i < len(nums):
            if left >= right:
                ans += 1

            num = nums[i]
            left += num
            right -= num

            i += 1
        
        return ans