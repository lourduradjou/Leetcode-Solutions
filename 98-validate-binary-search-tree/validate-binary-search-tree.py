# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        maxNumber = sys.maxsize

        def helper(node, mini, maxi):
            if not node:
                return True
            
            if mini < node.val < maxi:
                return helper(node.left, mini, node.val) and helper(node.right, node.val, maxi)
            else:
                return False
        
        return helper(root, -maxNumber, maxNumber)
