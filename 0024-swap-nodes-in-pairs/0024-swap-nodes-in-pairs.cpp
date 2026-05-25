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
    ListNode* swapPairs(ListNode* head) 
    {
        // Dummy node helps handle edge cases (like changing the head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // 'prev' always points to the node BEFORE the pair we are swapping
        ListNode* prev = dummy;
        // Traverse the list while there are at least 2 nodes to swap
        while (prev->next != nullptr && prev->next->next != nullptr) 
        {
            // Identify the two nodes to swap
            ListNode* first = prev->next;         // first node in pair
            ListNode* second = prev->next->next;  // second node in pair
            // ---- Swapping happens here ----
            // Step 1: point first to the node after second
            first->next = second->next;
            // Step 2: point second to first (this swaps them)
            second->next = first;
            // Step 3: connect previous part to second (new front)
            prev->next = second;
            // Move 'prev' forward for next swap
            prev = first;  // because 'first' is now the second node in the pair
        }
        // Return the new head (skip dummy)
        return dummy->next;
    }
};