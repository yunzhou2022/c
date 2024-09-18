/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        int flag = 1;
        for (int i = 0; s[i]; i++)
        {
            switch (s[i])
            {
            case '(':
            case '{':
            case '[':
                stk.push(s[i]);
                break;
            case ')':
                if (stk.size() == 0 || stk.top() != '(')
                {
                    flag = 0;
                }
                stk.pop();
                break;
            case '}':
                if (stk.size() == 0 || stk.top() != '{')
                {
                    flag = 0;
                }
                stk.pop();
                break;
            case ']':
                if (stk.size() == 0 || stk.top() != '[')
                {
                    flag = 0;
                }
                stk.pop();
                break;
            }
            if (flag == 0)
                break;
        }
        return stk.size() == 0 && flag == 1;
    }
};
// @lc code=end
