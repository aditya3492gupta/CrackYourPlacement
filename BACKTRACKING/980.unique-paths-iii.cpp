/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
class Solution
{
public:
    int x, y, xLen, yLen, countZeros = 0, totalZeros = 0, res = 0, cell;
    void dfs(vector<vector<int>> &grid, int x, int y)
    {
        // exit condition: out of bonds
        if (x < 0 || y < 0 || x == xLen || y == yLen)
            return;
        cell = grid[y][x];
        if (cell)
        {
            // increasing res if we reached the goal and touched all available cell
            res += cell == 2 && countZeros == totalZeros;
            return;
        }
        // marking cell as visited
        grid[y][x] = -1;
        countZeros++;
        // exploring north, east, south, west
        dfs(grid, x, y - 1);
        dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x - 1, y);
        // backtracking cell as visitable
        grid[y][x] = 0;
        countZeros--;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        // setting class variables right
        yLen = grid.size();
        xLen = grid[0].size();
        for (int _y = 0; _y < yLen; _y++)
        {
            for (int _x = 0; _x < xLen; _x++)
            {
                cell = grid[_y][_x];
                // finding the starting point
                if (cell == 1)
                {
                    x = _x;
                    y = _y;
                }
                // increasing countZeros for each cell == 0
                totalZeros += !cell;
            }
        }
        // exploring north, east, south, west of the starting point
        dfs(grid, x, y - 1);
        dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x - 1, y);
        return res;
    }
};
// @lc code=end
