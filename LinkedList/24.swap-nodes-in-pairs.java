/*
 * @lc app=leetcode id=24 lang=java
 *
 * [24] Swap Nodes in Pairs
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
    public ListNode swapPairs(ListNode head) {
        if (head == null || /* head != null && */ head.next == null)
            return head;

        ListNode result = head.next, curr = head, temp = head, prev = temp, nextPair = null;

        // while(head && head->next){}
        while (curr != null && curr.next != null) {
            // save next pair
            if (curr.next.next != null)
                nextPair = curr.next.next;
            else
                nextPair = null;
            temp = curr.next;

            // reverse pair
            temp.next = curr;
            curr.next = nextPair;
            // if (nextPair == null)
            // prev.next = nextPair;
            // else
            prev.next = temp;

            // update pairs
            prev = curr;
            curr = nextPair;
        }

        return result;
    }
}
// @lc code=end

/*
 * Test Case : [1,2] not matching
 * output = [2,1]
 */