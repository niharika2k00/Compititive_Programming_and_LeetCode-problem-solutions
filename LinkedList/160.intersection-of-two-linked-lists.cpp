/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * https://leetcode.com/problems/intersection-of-two-linked-lists/
 *
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        //  METHOD - I   (Hashing)
        //  Time Complexity :  O(len1 + len2)
        //  Space Complexity :  O(n)
        unordered_set<ListNode *> hashSet; // for storing the address of the nodes

        while (headA != NULL)
        {
            hashSet.insert(headA);
            headA = headA->next;
        }

        while (headB != NULL)
        {
            if (hashSet.find(headB) != hashSet.end()) // if found
                return headB;

            headB = headB->next;
        }

        return NULL;

        //  METHOD - II
        //  Time Complexity: O(2*max(length of list1,length of list2))
        //  Space Complexity : O(1)
        if (!headA || !headB)
            return NULL;

        ListNode *a = headA, *b = headB;

        while (a != b)
        {
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }

        return b;
    }
};
// @lc code=end

/*
                   Method 1 [Hashing]
               ----------------------------
    Use unordered_set for storing the address of the Nodes for a LL.
    Then traverse the LL2 and find whether it exists previously or not.


                  Method 2 [Length]
               -----------------------
    https://takeuforward.org/data-structure/find-intersection-of-two-linked-lists/

 */