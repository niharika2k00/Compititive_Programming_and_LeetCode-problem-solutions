/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * https://leetcode.com/problems/sort-list/
 *
 * [148] Sort List
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
    ListNode *mergeBothLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode();
        ListNode *newStart = dummy;

        if (!list1 && !list2)
            return list1;

        if (!list1 || !list2)
            return list1 ? list1 : list2;

        //  Merge both in Ascending Order
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                dummy->next = list1;
                list1 = list1->next;
            }

            else if (list2->val <= list1->val)
            {
                dummy->next = list2;
                list2 = list2->next;
            }

            dummy = dummy->next;
        }

        if (list1 != NULL)
            dummy->next = list1;
        if (list2)
            dummy->next = list2;

        return newStart->next;
    }

    //    MAIN _ FUNCTION
    ListNode *sortList(ListNode *head)
    {
        if (!head || head->next == nullptr)
            return head;

        ListNode *fast = head, *slow = head, *temp = NULL;

        //  Middle Element
        while (fast && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        //   2 Linked List created :  0  -  (slow - 1)    &&    slow  -  NULL
        //  Last Element of the First Half
        temp->next = NULL;

        //  Sort both the divided Lists
        ListNode *list1 = sortList(head);
        ListNode *list2 = sortList(slow);

        return mergeBothLists(list1, list2);
    }
};
// @lc code=end

/*
                    APPROACH   ||   INTUITION
                 ------------------------------------
    1)  First  find the MIDDLE of the Linked List
    2)  Divide & Conquer Rule  ==>  Divide into 2 Lists from the MID .
    3)  Then Merge in ASCENDING ORDER .

 */