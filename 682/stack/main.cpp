#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {
        std::stack<int> st;

        for(const auto& ops : operations)
        {
            if(ops == "+")
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.push(val1);
                st.push(val1 + val2);
            }
            else if(ops == "C")
            {
                st.pop();
            }
            else if(ops == "D")
            {
                int val = st.top() * 2;
                st.push(val);
            }
            else
            {
                st.push(atoi(ops.c_str()));
            }
        }

        int res = 0;
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<std::string> ops{"5","2","C","D","+"};
        ASSERT_EQ(30, obj->calPoints(ops));
    }
    {
        std::vector<std::string> ops{"5","-2","4","C","D","9","+","+"};
        ASSERT_EQ(27, obj->calPoints(ops));
    }
}