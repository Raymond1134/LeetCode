# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    class MinHeap:
        def __init__(self):
            self.heap = []

        @staticmethod
        def right(idx): return 2 * idx + 2

        @staticmethod
        def left(idx): return 2 * idx + 1

        @staticmethod
        def parent(idx): return (idx - 1) // 2

        def swap(self, idx1, idx2):
            self.heap[idx1], self.heap[idx2] = self.heap[idx2], self.heap[idx1]

        def heapifyDown(self):
            idx = 0

            while True:
                smallest = idx
                left = self.left(idx)
                right = self.right(idx)

                if left < len(self.heap) and self.heap[left].val < self.heap[smallest].val:
                    smallest = left

                if right < len(self.heap) and self.heap[right].val < self.heap[smallest].val:
                    smallest = right

                if smallest == idx:
                    break

                self.swap(idx, smallest)
                idx = smallest

        def heapifyUp(self):
            idx = len(self.heap) - 1

            while idx > 0:
                parent = self.parent(idx)

                if self.heap[idx].val >= self.heap[parent].val:
                    break

                self.swap(idx, parent)
                idx = parent

        def pop(self):
            if len(self.heap) == 1: return self.heap.pop()

            value = self.heap[0]
            self.heap[0] = self.heap.pop()
            self.heapifyDown()

            return value

        def insert(self, value):
            self.heap.append(value)
            self.heapifyUp()

    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0: return None
        headNode = ListNode()
        current = headNode
        nodeHeap = self.MinHeap()

        for node in lists:
            if node is not None:
                nodeHeap.insert(node)
        
        while nodeHeap.heap:
            minNode = nodeHeap.pop()
            current.next = minNode
            current = current.next

            if minNode.next: nodeHeap.insert(minNode.next)
        
        return headNode.next