#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int scoreOfParentheses(std::string s) {
        int score = 0;
        std::stack<char> st;

        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if(c == '(')
            {
                st.push(c);
            }
            else
            {
                st.pop();
                if(s[i - 1] == '(')
                    score += 1 << st.size();
            }
        }

        return score;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ(1, obj->scoreOfParentheses("()"));
    }
    {
        ASSERT_EQ(2, obj->scoreOfParentheses("(())"));
    }
    {
        ASSERT_EQ(2, obj->scoreOfParentheses("()()"));
    }
    {
        ASSERT_EQ(4, obj->scoreOfParentheses("(()())"));
    }
    {
        ASSERT_EQ(16, obj->scoreOfParentheses("(((()())))"));
    }
    {
        ASSERT_EQ(4, obj->scoreOfParentheses("((()))"));
    }
}
