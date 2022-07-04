/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
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
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *curr = head;
        int len = 0, temp = 0;

        //  Length of the Linked List
        while (curr != NULL)
        {
            len++;
            curr = curr->next;
        }

        cout << len << endl;
        int endPos = len - k + 1; //  from the Backward

        len = 0;
        ListNode *first = head, *second = head;

        while (first != NULL)
        {
            len++;
            if (len == k)
                break;

            first = first->next;
        }

        len = 0;
        while (second != NULL)
        {
            len++;
            if (len == endPos)
                break;

            second = second->next;
        }

        temp = first->val;
        first->val = second->val;
        second->val = temp;

        return head;
    }
};
