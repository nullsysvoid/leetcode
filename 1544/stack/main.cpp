#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::string makeGood(std::string s) {
        std::stack<char> st;

        for(auto i : s)
        {
            if (!st.empty() && i != st.top() && tolower(i) == tolower(st.top()))
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }

        std::string res;
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    ASSERT_EQ("leetcode", obj->makeGood("leEeetcode"));
    ASSERT_EQ("", obj->makeGood("abBAcC"));
    ASSERT_EQ("s", obj->makeGood("s"));
}
