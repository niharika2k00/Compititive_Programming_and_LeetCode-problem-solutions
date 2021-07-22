/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        int carry = 0, sum = 0;
        ListNode *AddList = new ListNode();
        ListNode *temp = AddList; // address of the start node of the new LinkedList

        while (l1 != NULL || l2 != NULL || carry)
        {

            if (l1 != NULL)
            {
                sum = l1->val + sum;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                sum = sum + l2->val;
                l2 = l2->next;
            }

            sum = sum + carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }

        return AddList->next;
    }
};
// @lc code=end
