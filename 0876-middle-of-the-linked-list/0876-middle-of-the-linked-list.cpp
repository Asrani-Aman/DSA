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
class Solution
{

public:
    int getLength(ListNode* head)
    {
        int count =0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
public:
    ListNode* middleNode(ListNode* head) {
       int length =  getLength(head);
        int mid = (length/2)+1;
        ListNode*  traceNode = head;
        // now travese the ll till mid
        int trace = 0;
        while(mid-trace-1!=0)
        {
            trace++;
            traceNode = traceNode->next;
        }
        return traceNode;
    }
    
};