/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &h)
    {
        int l = 0, r = h.size() - 1, lmax = h[l], rmax = h[r], res = 0;
        while (l < r)
        {
            if (lmax < rmax)
            {
                l += 1;
                lmax = max(lmax, h[l]);
                res += lmax - h[l];
            }
            else
            {
                r -= 1;
                rmax = max(rmax, h[r]);
                res += rmax - h[r];
            }
        }
        return res;
    }
};
// @lc code=end
