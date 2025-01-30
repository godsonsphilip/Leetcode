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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n,-1));
        int left = 0, right = n, top = 0, bottom = m;
        ListNode* temp = head;
        while (top < bottom and left < right) {
            // Moving right:
            for (int i = left; i < right && temp; i++) {    //Checking whether temp is not null:
                result[top][i] = temp->val;
                temp = temp->next;
            }
            top++;

            // Moving down:
            for (int i = top; i < bottom and temp; i++) {
                result[i][right - 1] = temp->val;
                temp = temp->next;
            }
            right--;

            if (left >= right || top >= bottom)
                break;

            // Moving left:
            for (int i = right - 1; i >= left and temp; i--) {
                result[bottom - 1][i] = temp->val;
                temp = temp->next;
            }
            bottom--;

            // Moving up:
            for (int i = bottom - 1; i >= top and temp; i--) {
                result[i][left] = temp->val;
                temp = temp->next;
            }
            left++;
        }
        return result;
    }
};