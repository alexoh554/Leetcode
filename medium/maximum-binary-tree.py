# Time complexity: O(n^2)
# Space complexity: O(n)
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        if len(nums) == 0:
            return 
        maxValue = max(nums)
        maxIndex = nums.index(maxValue)

        leftMax = self.constructMaximumBinaryTree(nums[:maxIndex])
        rightMax = self.constructMaximumBinaryTree(nums[maxIndex + 1:])

        node = TreeNode(maxValue)
        if leftMax:
            node.left = leftMax
        if rightMax:
            node.right = rightMax

        return node