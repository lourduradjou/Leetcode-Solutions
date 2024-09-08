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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        //vector to store the answers and return
        vector<ListNode*> ans(k, NULL);

        ListNode *cur = head, *prev = NULL;
        int len = 0;

        while(cur) {
            len++;
            cur = cur->next;
        }

        int n = len / k, rem = len % k;
        cur = head; //reusing the declared cur for to iterate over the linked list

        for (int i = 0; i < k && cur; i++, rem--) {
            ans[i] = cur; //storing the starting point
            for (int j = 0; j < n + (rem > 0); j++) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = NULL;
        }


        return ans;
    }
};