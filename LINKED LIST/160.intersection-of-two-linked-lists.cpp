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
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr or headB == nullptr)
            return nullptr;
        while (headA != nullptr and headB != nullptr)
        {
            if (headA->val < headB->val)
                headA = headA->next;
            else if (headA->val > headB->val)
                headB = headB->next;
            else
                return headA;
        }
        return nullptr;
    }
};
// @lc code=end
