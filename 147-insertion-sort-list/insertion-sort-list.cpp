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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* start = head;
        while(start) {
            ListNode* temp = head;
            while(temp != start) {
                if(temp->val > start->val)
                    swap(temp->val, start->val);
                temp = temp->next;
            }
            start = start->next;
        }
        return head;
    }
};