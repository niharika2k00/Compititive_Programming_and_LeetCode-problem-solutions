/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * * https://leetcode.com/problems/reverse-linked-list/
 *
 * [206] Reverse Linked List
 */

// @lc code=start
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
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head, *temp, *prevNode = NULL; // prevNode stores the previous address.

        while (curr != NULL)
        {
            temp = curr->next; // address
            curr->next = prevNode;
            prevNode = curr;
            curr = temp;
        }

        return prevNode; //  curr / last Node
    }
};
// @lc code=end
