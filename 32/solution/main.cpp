#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils/utils.h>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> st;
        int res = 0;
        int cur = 0;

        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if(c == ')')
            {
                if(!st.empty() && s[st.top()] == '(')
                {
                    st.pop();
                    cur = (st.empty() ? i + 1 : i - st.top());
                    res = std::max(cur, res);
                }
                else
                {
                    st.push(i);
                }
            }
            else
            {
                st.push(i);
            }
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ(2, obj->longestValidParentheses("(()"));
    }
    {
        ASSERT_EQ(132, obj->longestValidParentheses(")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())"));
    }
    

}
