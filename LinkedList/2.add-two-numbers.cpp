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
 *
 * https://leetcode.com/problems/add-two-numbers/
 *
 */
class Solution
{
public:
    //  m and n represent the length of l1 and l2
    //  Time Complexity: O(max(m,n)).
    //  Space Complexity: O(max(m,n)).

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = new ListNode(0);
        ListNode *ptr = NULL;
        ptr = l3; // pointer(head)  pointing to the l3.

        int carry = 0, add = 0;

        while (l1 != NULL || l2 != NULL || carry) // untill carry ends
        {
            add = 0;
            if (l1)
            {
                add = add + l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                add = add + l2->val;
                l2 = l2->next;
            }

            add += carry;

            if (add > 9) // carry
            {
                carry = add / 10;
                add = (add % 10);
            }

            // newNode->val = add ;
            ListNode *newNode = new ListNode(add);

            ptr->next = newNode; // address set
            ptr = ptr->next;
        }

        return l3->next;
    }
};
// @lc code=end

/*
      Example :

      Input :
       [9,9,9,9,9,9,9]
       [9,9,9,9]

      Output :
       [8,9,9,9,0,0,0,1]
 */