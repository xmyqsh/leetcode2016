# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        if not t:
            return ''
        left = self.tree2str(t.left)
        right = self.tree2str(t.right)
        if len(right):
            return ''.join([str(t.val), '(', left, ')', '(', right, ')'])
        elif len(left):
            return ''.join([str(t.val), '(', left, ')'])
        else:
            return str(t.val)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        if not t: return ''
        left = '({})'.format(self.tree2str(t.left)) if (t.left or t.right) else ''
        right = '({})'.format(self.tree2str(t.right)) if (t.right) else ''
        return '{}{}{}'.format(t.val, left, right)
