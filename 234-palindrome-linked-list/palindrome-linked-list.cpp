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
    bool isPalindrome(ListNode* head) {
        string result;
        auto temp = head;
        while(temp){
            result += temp->val;
            temp = temp->next;
        }
        return isPal(result);
    }

    bool isPal(string result){
        int n = result.size();
        int l = 0, r = n-1;
        while(l<=r){
            if(result[l]!=result[r]) return false;
            l++; r--;
        }
        return true;
    }
};