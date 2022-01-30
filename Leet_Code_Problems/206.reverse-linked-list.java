/*
 * @lc app=leetcode id=206 lang=java
 *
 * https://leetcode.com/problems/reverse-linked-list/
 * 
 * [206] Reverse Linked List
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
    public ListNode reverseList(ListNode head) {
        ListNode curr = head, temp, newHead = null;

        while (curr != null) {
            temp = curr.next; // address
            curr.next = newHead;
            newHead = curr;
            curr = temp;
        }

        return newHead;
    }
}
// @lc code=end
