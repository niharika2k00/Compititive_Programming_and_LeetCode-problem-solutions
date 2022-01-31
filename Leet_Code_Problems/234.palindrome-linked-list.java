/*
 * @lc app=leetcode id=234 lang=java
 *
 * [234] Palindrome Linked List
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
 * 
 * https://leetcode.com/problems/palindrome-linked-list/
 * 
 */
class Solution {

    public ListNode midPoint(ListNode head) {
        ListNode slow = head, fast = head;

        while (fast != null && fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next; // Jump 2 step
        }

        return slow;
    }

    public ListNode reverseList(ListNode curr) {
        ListNode temp, newPtr = null;

        while (curr != null) {
            temp = curr.next;
            curr.next = newPtr;
            newPtr = curr;
            curr = temp;
        }

        return newPtr;
    }

    public boolean isPalindrome(ListNode head) {

        ListNode curr, newPtr = null;
        boolean result = false;

        // Mid - Point of the LinkedList
        ListNode mid = midPoint(head);

        // Reverse the Part of the LinkedList after K
        ListNode slow = reverseList(mid.next); // slow -> next

        // Check Left & Right HALF EQUAL OR NOT
        // START/HEAD ---> Left part , SLOW ---> Right part
        while (slow != null) {
            if (head.val != slow.val)
                return false;

            head = head.next;
            slow = slow.next;
        }

        return true;
    }
}
// @lc code=end

/*
 * For Algorithm refer to copy
 */

/*        *****       We can also use STACK , but then  SPACE COMPLEXITY  : O(n)         *****
   
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* temp = head;
        while(temp!=NULL){
            s.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL || !s.empty()){
            int val = s.top();
            s.pop();
            if(val!=temp->val) return false;
            temp = temp->next;
        }
        return true;
    }
*/