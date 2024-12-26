class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        currentMax = nums[0]
        currentMin = nums[0]

        ans = nums[0]

        for i in range(1, len(nums)):
            if nums[i] < 0:
                currentMax, currentMin = currentMin, currentMax

            currentMax = max(nums[i], currentMax * nums[i], 0)
            currentMin = min(nums[i], currentMin * nums[i], 0)

            ans = max(ans, currentMax)

        return ans