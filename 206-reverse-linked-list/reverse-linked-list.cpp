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
        if(!head) return head;
        auto temp = head;
        ListNode* prev = NULL;
        ListNode* next1 = head->next;
        while(temp){
            temp->next = prev;
            prev = temp;
            temp = next1;
            if(next1)next1 = next1->next;
        }
        return prev;
    }
};