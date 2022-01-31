/*
 * @lc app=leetcode id=61 lang=java
 *
 * [61] Rotate List
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
    public ListNode rotateRight(ListNode head, int k) {
        // edge case
        if (head == null || k == 0)
            return head;

        ListNode curr = head;
        int len = 1;

        // Lenght of the LinkedList
        while (curr.next != null) {
            curr = curr.next;
            ++len;
        }

        k = k % len;

        // Circular Linkedlist
        curr.next = head;

        // k - times Shift
        while (k-- != 0)
            curr = curr.next;

        head = curr.next;
        curr.next = null;

        System.out.println(len);

        return head;
    }
}
// @lc code=end
