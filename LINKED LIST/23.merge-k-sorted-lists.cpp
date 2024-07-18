/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            ListNode *temp = lists[i];
            while (temp != nullptr)
            {
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode *ans = new ListNode();
        ListNode *t = ans;
        while (!pq.empty())
        {
            ListNode *l = new ListNode(pq.top());
            pq.pop();
            t->next = l;
            t = t->next;
        }
        return ans->next;
    }
};
// @lc code=end
