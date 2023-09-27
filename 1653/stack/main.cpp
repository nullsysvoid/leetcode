#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int minimumDeletions(std::string s) {
        std::stack<char> st;
        int res = 0;

        for(auto c : s)
        {
            if(!st.empty() && st.top() == 'b' && c == 'a')
            {
                res++;
                st.pop();
            }
            else
                st.push(c);
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ(2, obj->minimumDeletions("aababbab"));
    }
}

