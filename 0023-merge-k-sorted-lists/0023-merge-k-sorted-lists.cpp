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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        // Min heap: stores the smallest current node among all lists
        auto cmp = [](ListNode* a, ListNode* b) 
        {
            return a->val > b->val; // min heap
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        // Step 1: Push the head of each list into the heap
        for (ListNode* list : lists) 
        {
            if (list != nullptr) 
            {
                pq.push(list);
            }
        }
        // Dummy node to simplify building the result list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        // Step 2: Process the heap
        while (!pq.empty()) 
        {
            ListNode* smallest = pq.top(); // get smallest node
            pq.pop();
            // Add it to the merged list
            tail->next = smallest;
            tail = tail->next;
            // If there's a next node in the same list, push it into heap
            if (smallest->next != nullptr) 
            {
                pq.push(smallest->next);
            }
        }
        return dummy->next; // skip dummy node
    }
};