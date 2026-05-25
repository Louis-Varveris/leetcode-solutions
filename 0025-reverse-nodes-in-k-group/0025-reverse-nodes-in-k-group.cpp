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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        // Dummy node to simplify edge cases (like changing head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // 'prevGroupEnd' points to the node before the current group
        ListNode* prevGroupEnd = dummy;
        while (true) 
        {  
            // Step 1: Check if there are at least k nodes left
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k && kth != nullptr; i++) 
            {
                kth = kth->next;
            }
            // If fewer than k nodes remain, stop
            if (kth == nullptr) break;
            // Step 2: Identify group boundaries
            ListNode* groupStart = prevGroupEnd->next; // first node in group
            ListNode* nextGroupStart = kth->next;      // node after the group
            // Step 3: Reverse the k nodes
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;
            while (curr != nextGroupStart) 
            {
                ListNode* temp = curr->next; // save next node
                curr->next = prev;           // reverse pointer
                prev = curr;                 // move prev forward
                curr = temp;                 // move curr forward
            }
            // Step 4: Connect reversed group back to list
            prevGroupEnd->next = kth;        // kth is new head after reverse
            prevGroupEnd = groupStart;       // move to end of current group
        }
        return dummy->next;
    }
};