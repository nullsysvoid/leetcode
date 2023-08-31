#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for(auto c : s)
        {
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            else if(!st.empty())
            {
                if((c == ')' && st.top() == '(') ||
                   (c == ']' && st.top() == '[') ||
                   (c == '}' && st.top() == '{'))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
                return false;
        }

        return st.empty();
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
        ASSERT_EQ(true, obj->isValid("()"));
        ASSERT_EQ(true, obj->isValid("()[]{}"));
        ASSERT_EQ(false, obj->isValid("(]"));
        ASSERT_EQ(true, obj->isValid("{[]}"));      
}