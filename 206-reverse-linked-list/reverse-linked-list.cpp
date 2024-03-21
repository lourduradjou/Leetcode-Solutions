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
        // //using the method of changing the pointers withing the node 
        // ListNode *prev = NULL;
        // ListNode *curr = head;

        // while(curr != NULL)//until it reaches last element
        // {
        //     ListNode *forw = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = forw;
        // }
        // return prev;
        // //prev contains the address of the last value finally 

        //another approach using recursion 
        if(head == NULL || head->next == NULL) return head;
        ListNode *revHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return revHead;
    }
};