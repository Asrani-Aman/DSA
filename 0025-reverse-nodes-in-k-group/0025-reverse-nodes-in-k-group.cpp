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
        ListNode* temp = head;
        ListNode* ans = nullptr;
        int listitems = 0;
        while(temp !=nullptr)
        {
            listitems++;
            temp=temp->next;
        }
        // base condition
        if(listitems < k )
        {
            //return ans;
            return head;
        }
    
        int count = 0;
        ListNode* current = head;
        ListNode* prev =nullptr;

        while(count < k)
        {
            ListNode* forward = current->next;
          //  forward->next = current;
            current->next = prev;
            if(prev==nullptr) ans  = current;
            prev = current;
            current = forward;
            count++;
        }
      //  reverseKGroup(current , k);
        head->next = reverseKGroup(current, k);
        return prev;
    }
};
