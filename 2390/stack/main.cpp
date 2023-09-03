#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::string removeStars(std::string s) {
        std::stack<char> st;

        for(auto c : s)
        {
            if(c == '*')
            {
                if(!st.empty())
                   st.pop();
            }
            else
            {
                st.push(c);
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
    ASSERT_EQ("lecoe", obj->removeStars("leet**cod*e"));
    ASSERT_EQ("", obj->removeStars("erase*****"));
}