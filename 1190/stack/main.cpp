#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::stack<std::string> st;

        std::string tmp;
        for(auto c : s)
        {
            if(c == '(')
            {
                st.push(tmp);
                tmp.clear();
            }
            else if(c == ')')
            {
                reverse(tmp.begin(), tmp.end());
                tmp = st.top() + tmp;
                st.pop();
            }
            else
            {
                tmp += c;
            }
        }

        return tmp;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ("dcba", obj->reverseParentheses("(abcd)"));
    }
    {
        ASSERT_EQ("iloveu", obj->reverseParentheses("(u(love)i)"));
    }
    {
        ASSERT_EQ("leetcode", obj->reverseParentheses("(ed(et(oc))el)"));
    }
}
