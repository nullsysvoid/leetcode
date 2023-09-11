#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    std::string removeDuplicates(std::string s) {
        std::stack<char> st;
        for(auto c : s)
        {
            if(!st.empty() && st.top() == c)
            {
                st.pop();

            }
            else
                st.push(c);
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
    std::shared_ptr obj = std::make_shared<Solution>();
    {
        ASSERT_EQ("ca", obj->removeDuplicates("abbaca"));
    }
    {
        ASSERT_EQ("ay", obj->removeDuplicates("azxxzy"));
    }
}
