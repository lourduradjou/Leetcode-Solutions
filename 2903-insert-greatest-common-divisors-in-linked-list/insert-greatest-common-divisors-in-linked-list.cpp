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

    int gcd(int a, int b) {
        int temp;
        while(b != 0) {
            temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        int firstNum, secondNum;

        while (cur != NULL && cur->next != NULL) {  
            firstNum = cur->val;        
            secondNum = cur->next->val;
            //cout<<firstNum<<" "<<secondNum<<endl;
            //creating the new node
            ListNode* newNode = new ListNode(gcd(firstNum, secondNum));
            newNode->next = cur->next;
            cur->next = newNode;
            //move to the next node
            cur = newNode->next;
        }

        return head;
    }
};