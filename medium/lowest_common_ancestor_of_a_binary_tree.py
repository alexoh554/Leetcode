# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Base case
        if root is None or root.val == p.val or root.val == q.val:
            return root

        # Run recurisvely on left and right
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)

        # Case 1: Left and right are both non null
        if left and right:
            return root
        
        # Case 2: only left or only right
        if left:
            return left
        return right
