/*
 * @lc app=leetcode id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 */

// @lc code=start
class Solution
{
public:
    int furthestBuilding(vector<int> &h, int b, int l)
    {
        int n = h.size();
        priority_queue<int> p;
        int diff = 0, cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            diff = h[i + 1] - h[i];
            if (diff > 0)
            {
                b -= diff;
                p.push(diff);
                if (b < 0)
                {
                    b += p.top();
                    p.pop();
                    l--;
                }
                if (l < 0)
                    break;
            }
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end
