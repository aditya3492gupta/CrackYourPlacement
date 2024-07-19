/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.length() < needle.length())
        {
            return -1;
        }

        for (int i = 0; i <= haystack.length() - needle.length(); i++)
        {
            if (haystack.substr(i, needle.length()) == needle)
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end
