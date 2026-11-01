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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;

        while (mid) {
            ListNode* temp = mid->next;
            mid->next = prev;
            prev = mid;
            mid = temp;
        }

        ListNode* start = head;

        while (prev) {
            ListNode* temp = start->next;
            ListNode* temp2 = prev->next;
            start->next = prev;
            prev->next = temp;
            start = temp;
            prev = temp2;
        }
    }
};
