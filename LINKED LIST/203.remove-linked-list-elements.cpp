/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return head;
        while (head != nullptr && head->val == val)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
        ListNode *current = head;
        while (current != nullptr && current->next != nullptr)
        {
            if (current->next->val == val)
            {
                ListNode *temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
};
// @lc code=end
