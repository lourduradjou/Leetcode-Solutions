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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSums;
        prefixSums[0] = dummy;
        ListNode* current = head;

        while (current) {
            prefixSum += current->val;
            //if the values come somewhere down the line
            if (prefixSums.find(prefixSum) != prefixSums.end()) {
                ListNode* toDelete = prefixSums[prefixSum]->next;
                int tempSum = prefixSum + toDelete->val;

                while (toDelete != current) {
                    prefixSums.erase(tempSum);
                    toDelete = toDelete->next;
                    tempSum += toDelete->val;
                }
                prefixSums[prefixSum]->next = current->next;
            } else {
                prefixSums[prefixSum] = current;
            }
            current = current->next;
        }

        return dummy->next;
    }
};