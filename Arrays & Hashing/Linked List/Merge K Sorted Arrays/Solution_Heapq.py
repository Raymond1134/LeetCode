# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0: return None
        headNode = ListNode()
        current = headNode
        nodeHeap = []

        for i, node in enumerate(lists):
            if node is not None:
                heapq.heappush(nodeHeap, (node.val, i, node))
        
        while nodeHeap:
            _, i, minNode = heapq.heappop(nodeHeap)
            current.next = minNode
            current = current.next
            if minNode.next: heapq.heappush(nodeHeap, (minNode.next.val, i, minNode.next))
        
        return headNode.next