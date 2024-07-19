/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else
            {
                if (st.empty() or (c == ')' and st.top() != '(') or (c == '}' and st.top() != '{') or
                    (c == ']' and st.top() != '['))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end
