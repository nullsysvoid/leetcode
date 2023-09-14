#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    std::string smallestNumber(std::string pattern) {
        std::stack<int> st;
        std::string res;

        for(int i = 0; i <= pattern.size(); i++)
        {
            st.push(i + 1);
            if(pattern[i] == 'I' || pattern.size() == i)
            {
                while(!st.empty())
                {
                    res += std::to_string(st.top());
                    st.pop();
                }
            }
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ("123549876", obj->smallestNumber("IIIDIDDD"));
        ASSERT_EQ("4321", obj->smallestNumber("DDD"));
    }
}
