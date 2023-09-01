
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        int count = 0;

        // Count the number of nodes in the current group
        while (current != nullptr && count < k) {
            current = current->next;
            count++;
        }

        // If there are at least k nodes in the current group, reverse them
        if (count == k) {
            current = reverseKGroup(current, k); // Reverse the next k nodes recursively

            // Reverse the current group of k nodes
            while (count > 0) {
                ListNode* next = head->next;
                head->next = current;
                current = head;
                head = next;
                count--;
            }

            // 'current' now points to the new head of the reversed group
            return current;
        }

        // If there are less than k nodes, no need to reverse, return the head
        return head;
    }
};
