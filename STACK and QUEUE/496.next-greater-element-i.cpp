/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // vector<int>ans;
        int n = nums2.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and nums2[st.top()] < nums2[i])
                st.pop();
            if (st.size() > 0)
                ans[i] = nums2[st.top()];
            st.push(i);
        }
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums2.size(); i++)
            mpp[nums2[i]] = ans[i];
        vector<int> final(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++)
            if (mpp.find(nums1[i]) != mpp.end())
                final[i] = mpp[nums1[i]];
        return final;
    }
};
// @lc code=end