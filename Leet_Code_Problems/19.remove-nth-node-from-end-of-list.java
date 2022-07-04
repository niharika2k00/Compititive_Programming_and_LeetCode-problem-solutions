/*
 * @lc app=leetcode id=19 lang=java
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {

        if (head.next == null)
            return null;

        ListNode start = new ListNode(-1);
        start.next = head;
        ListNode slow = start, fast = start;
        int i;

        for (i = 0; i < n; i++)
            fast = fast.next;

        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }

        slow.next = slow.next.next;

        return start.next;
    }
}
// @lc code=end


/*                       APPROACHES 
                    ---------------------

    Method - 1 (Naive Approach)
    1) Count the Len of the LinkedList O(n)
    2) n = Len - n , EX- (5 - 2 = 3) , means 3rd NODE from the beginning need to be delete.

               Time Complexity : O(n) + O(n)  =  O(2n)

    Method - 2  (Two Pointer Approach)
    1) Move fast pointer n - th times,           
    2) Then the Slow Pointer +1 step.     
                 Fast - Slow = N 
         
*/