/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 *
 * https://leetcode.com/problems/linked-list-cycle/
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        //  Fast & Slow Pointer
        //  Time Complexity :  O(N)
        //   Space Complexity :  O(1)
        ListNode *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;

        //   Hashing using Unordered_Set
        //  Time Complexity :  O(N)
        //  Space Complexity :  O(N)
        unordered_set<ListNode *> hashSet;

        while (head != NULL)
        {
            if (hashSet.find(head) != hashSet.end())
                return true;
            hashSet.insert(head);
            head = head->next;
        }

        return false;
    }
};
// @lc code=end
