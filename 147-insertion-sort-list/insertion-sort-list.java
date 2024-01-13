/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode curr = head;
        ListNode prev = null;
        
        while(curr != null){
            if(prev != null && prev.val > curr.val){
                ListNode temp = head;
                while(temp != curr){
                    if(temp.val > curr.val){
                        int val = temp.val;
                        temp.val = curr.val;
                        curr.val = val;
                    }
                    temp = temp.next;
                }
            }
            prev = curr;
            curr = curr.next;
        }
        return head;
    }
}