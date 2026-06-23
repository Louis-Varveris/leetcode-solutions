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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (!head || !head->next || k == 0)
            return head;

        // Find length and tail
        int n = 1;
        ListNode* tail = head;
        while (tail->next)
        {
            tail = tail->next;
            n++;
        }
        k %= n;
        if (k == 0)
            return head;
        // Make circular list
        tail->next = head;
        // Find new tail
        int steps = n - k - 1;
        ListNode* newTail = head;
        while (steps--)
            newTail = newTail->next;
        // New head
        ListNode* newHead = newTail->next;
        // Break circle
        newTail->next = nullptr;
        return newHead;
    }
};