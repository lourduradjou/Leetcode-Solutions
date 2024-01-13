/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var insertionSortList = function(head) {
    let curr = head;
    let prev = null;
    
    while(curr){
        if(prev && prev.val > curr.val){
            let temp = head;
            while(temp != curr){
                if(temp.val > curr.val){
                    let val = temp.val;
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
};