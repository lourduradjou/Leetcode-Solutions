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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

           ListNode *fast = head, *slow = head;
           for(int i=0; i<n; i++) 
           {
               fast = fast->next;
           }

           if(fast == NULL) {
               ListNode* ans = head->next;
               delete head;
               return ans;
           }
           //if fast == NULL means they are asking to delete the first node

           while(fast != NULL && fast->next != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            
            if(slow->next != NULL) {
                ListNode* to_delete = slow->next;
                slow->next = slow->next->next;
                delete to_delete;
            }
                
            return head;
    }
};