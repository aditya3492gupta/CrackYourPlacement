/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 */

// @lc code=start
class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();

        priority_queue<int> pq;
        curr = startFuel; // my current position
        int i = 0;        // station index
        int result = 0;
        while (curr < target)
        {
            while (i < n && curr >= stations[i][0])
            {

                pq.push(stations[i][1]);
                i++;
            }

            if (pq.empty()) // we can't move further now
                return -1;

            int dist = pq.top();
            pq.pop();

            curr += dist;
            result++;
        }

        return result;
    }
};
// @lc code=end
