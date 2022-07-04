/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(NULL); //  NULL assigned to the dummy node.
        ListNode *newStart = dummy;

        //  Base Case
        if (list1 == NULL && list2 == NULL)
            return list1; // NULL

        //  if(!list1 || !list2) return list1 ? list1 : list2;
        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                dummy->next = list1;
                list1 = list1->next;
            }

            else if (list1->val > list2->val)
            {
                dummy->next = list2;
                list2 = list2->next;
            }

            dummy = dummy->next; // dummy also shifts
        }

        // Now if only 1 List remaining , means if List1 NOT FULLY TRAVERSED
        if (list1 != NULL)
            dummy->next = list1;
        if (list2)
            dummy->next = list2;

        return newStart->next;
    }
};
// @lc code=end
