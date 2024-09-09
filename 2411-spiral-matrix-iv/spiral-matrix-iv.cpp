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
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int left = 0, top = 0, bottom = m-1, right = n-1;
        ListNode* cur = head;

        while (cur != NULL) {
            
            if (top <= bottom) {
                for (int i = left; cur != NULL && i <= right; i++) {
                    ans[top][i] = cur->val;
                    cur = cur->next;
                }
                top++;
            }

            if (left <= right) {
                for (int i = top; cur != NULL && i <= bottom; i++) {
                    ans[i][right] = cur->val;
                    cur = cur->next;
                }
                right--;
            }

            if (top <= bottom) {
                for (int i = right; cur != NULL && i >= left; i--) {
                    ans[bottom][i] = cur->val;
                    cur = cur->next;
                }
                bottom--;
            }
            
            if (left <= right) {
                for (int i = bottom; cur != NULL && i >= top; i--) {
                    ans[i][left] = cur->val;
                    cur = cur->next;
                }
                left++;
            }
        }

        return ans;
    }
};