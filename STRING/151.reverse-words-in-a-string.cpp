/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        stack<char> st;
        string ans;
        int word = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                word++;
            }
        }
        int a = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && st.empty())
            {
                continue;
            }
            if (s[i] != ' ')
            {
                st.push(s[i]);
            }
            else
            {
                while (!st.empty())
                {
                    ans += st.top();
                    st.pop();
                    a++;
                }
                if (a != word)
                {
                    ans += ' ';
                }
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
// @lc code=end
