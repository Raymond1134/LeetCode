/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int counter = 0;
        ListNode* back = head;
        ListNode* front = head;

        while (counter < n) {
            front = front->next;
            counter++;
        }

        if (front == nullptr) return head->next;
        
        while (front->next) {
            front = front->next;
            back = back->next;
        }

        back->next = back->next->next;

        return head;
    }
};
