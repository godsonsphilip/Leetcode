/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        auto temp = head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        //By using slow and fast pointer approach:
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                auto slow = head;
                fast = fast->next;
                // After the first meetup, start slow again from head and then move fast one step at time
                while(fast){
                    if(slow==fast) return slow;
                    slow = slow->next;
                    fast = fast->next;
                }
            }

        }
        return NULL;
    }
};