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
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while(curr){
            if(prev && prev->val > curr->val){
                ListNode* temp = head;
                while(temp != curr){
                    if(temp->val > curr->val){
                        int val = temp->val;
                        temp->val = curr->val;
                        curr->val = val;
                    }
                    temp = temp->next;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};