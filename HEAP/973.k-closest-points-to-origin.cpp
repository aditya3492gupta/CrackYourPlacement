/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, vector<int>>> pq;
        int n = points.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({points[i][0] * points[i][0] + points[i][1] * points[i][1], {points[i][0], points[i][1]}});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while (pq.size() > 0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end
