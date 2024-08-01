/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
// C++ program to return the number of
int countSquareMatrices(int a[][m],
                        int N, int M)
{
    int count = 0;

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            if (a[i][j] == 0)
                continue;

            a[i][j] = min(min(a[i - 1][j],
                              a[i][j - 1]),
                          a[i - 1][j - 1]) +
                      1;
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            count += a[i][j];

    return count;
}
// @lc code=end
