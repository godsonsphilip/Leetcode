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
    ListNode* reverseList(ListNode* head) {
        if(!head  or !head->next) return head;
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* n = temp->next;

        temp->next = prev;
        prev = temp;
        temp = n;

        while(temp){
            n = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = n;
        }

        head = prev;
        return head;

    }
};