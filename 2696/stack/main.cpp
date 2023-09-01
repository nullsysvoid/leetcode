#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int minLength(std::string s) {
        std::stack<char> st;
        for(auto c : s)
        {
            if(c == 'B')
            {
                if(!st.empty() && st.top() == 'A')
                    st.pop();
                else
                    st.push(c);
            }
            else if(c == 'D')
            {
                if(!st.empty() && st.top() == 'C')
                    st.pop();
                else
                    st.push(c);
            }
            else
                st.push(c);
        }

        return st.size();
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
        ASSERT_EQ(2, obj->minLength("ABFCACDB"));
        ASSERT_EQ(5, obj->minLength("ACBBD"));
        ASSERT_EQ(1, obj->minLength("AABBB"));
}