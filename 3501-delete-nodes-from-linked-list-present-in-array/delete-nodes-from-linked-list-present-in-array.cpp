#include <unordered_set>

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Dummy node to handle deletion at the head of the list
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* cur = head;

        unordered_set<int> check(nums.begin(), nums.end());
        
        while (cur != NULL) {
            int curNum = cur->val;

            // If the current value exists in the nums set 
            if (check.find(curNum) != check.end()) {
                // Remove the node
                prev->next = cur->next;
                // No need to update prev here because cur is deleted
                // prev should move to curr only if there is no deletion
                // else let it stay there, so that we can make a 
            } else {
                prev = cur;  // Update prev only if no deletion
            }

            cur = cur->next;  // Move to the next node
        }

        // Return the new head of the list
        return dummy->next;
    }
};
