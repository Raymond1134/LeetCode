class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        idxMap = {val: idx for idx, val in enumerate(inorder)}

        def recurse(preIdx, inLeft, inRight):
            if inLeft > inRight: return None, preIdx

            rootVal = preorder[preIdx]
            rootIdx = idxMap[rootVal]

            left, preIdx = recurse(preIdx + 1, inLeft, rootIdx - 1)
            right, preIdx = recurse(preIdx, rootIdx + 1, inRight)

            return TreeNode(rootVal, left, right), preIdx

        root, _ = recurse(0, 0, len(inorder) - 1)
        return root