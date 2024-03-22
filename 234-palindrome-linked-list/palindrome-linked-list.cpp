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
    //third solution changing the node pointing itself to solve the problem in O(1) space complexicity;

    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast  != NULL && fast->next != NULL) {      
            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast != NULL) slow = slow->next; 
        ListNode *prev = NULL;
        ListNode *temp = NULL;
        while(slow != NULL) {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }//this changes the next half finally we can compare this ll
 
        ListNode *start = head, *end = prev;
        while(start != NULL && end != NULL) {
            if(start->val != end->val)
                return false;
            end = end->next;
            start = start->next;
        }

        return true;
    }
};