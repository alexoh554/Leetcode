# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return

        self.invertTree(root.left)
        self.invertTree(root.right)

        self.swapChildren(root)

        return root
    

    def swapChildren(self, parent):
        temp = parent.left
        parent.left = parent.right
        parent.right = temp
        
