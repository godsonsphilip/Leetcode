class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *a = nullptr, *b = nullptr, *c = nullptr, *d = nullptr;
        ListNode *t = head;
        bool key1 = false, key2 = false;
        
        while (t) {
            if (t->val < x) {
                if (!key1) { 
                    a = d = t; 
                    key1 = true; 
                } else {
                    a->next = t;
                    a = a->next;
                }
            } else {
                if (!key2) { 
                    b = c = t; 
                    key2 = true;
                } else {
                    b->next = t;
                    b = b->next;
                }
            }
            t = t->next;
        }

        if (b) b->next = nullptr;
        if (a) a->next = c;

        return d ? d : c;
    }
};
