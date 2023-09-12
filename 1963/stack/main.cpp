#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int minSwaps(std::string s) {
        std::stack<char> st;
        for(auto c : s)
        {
            if(c == '[')
                st.push(c);
            else
            {
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                    st.push(c);
            }
        }

        return (st.size() / 2 + 1) / 2;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    ASSERT_EQ(1, obj->minSwaps("][]["));
    ASSERT_EQ(2, obj->minSwaps("]]][[["));
    ASSERT_EQ(0, obj->minSwaps("[]"));
}
