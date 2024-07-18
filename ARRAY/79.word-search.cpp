/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution
{
public:
    bool gen(vector<vector<char>> &board, string word, int i, int j, int ind, int n, int m)
    {
        if (ind == word.size())
            return true;
        if (i < 0 or j < 0 or i == n or j == m or board[i][j] != word[ind] or board[i][j] == '!')
            return false;
        char c = board[i][j];
        board[i][j] = '!';
        bool top = gen(board, word, i - 1, j, ind + 1, n, m);
        bool bot = gen(board, word, i + 1, j, ind + 1, n, m);
        bool r = gen(board, word, i, j + 1, ind + 1, n, m);
        bool l = gen(board, word, i, j - 1, ind + 1, n, m);
        board[i][j] = c;
        return top or bot or r or l;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[ind])
                    if (gen(board, word, i, j, ind, n, m))
                        return true;
            }
        }
        return false;
    }
};
// @lc code=end
