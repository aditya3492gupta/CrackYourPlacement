/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int totalTime = 0;
        int i = 0, j = 0;
        while (i < neededTime.size() && j < neededTime.size())
        {
            int currTotal = 0, currMax = 0;

            while (j < neededTime.size() && colors[i] == colors[j])
            {
                currTotal += neededTime[j];
                currMax = max(currMax, neededTime[j]);
                j++;
            }

            totalTime += currTotal - currMax;
            i = j;
        }
        return totalTime;
    }
};

// @lc code=end
