/*
 * @lc app=leetcode id=83 lang=java
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * 
 * [83] Remove Duplicates from Sorted List
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
    public ListNode deleteDuplicates(ListNode head) {

        ListNode temp = head;

        if (head == null)
            return head;

        while (temp != null) {
            if ((temp.next != null) && (temp.val == temp.next.val)) {
                temp.next = temp.next.next;
            } else
                temp = temp.next;
        }

        return head;
    }
}
// @lc code=end
