#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int minOperations(std::vector<std::string>& logs) {
        std::stack<int> st;

        for(const auto& s : logs)
        {
            if(s == "../")
            {
                if(!st.empty())
                    st.pop();
            }
            else if(s == "./")
            {
                continue;
            }
            else
            {
                st.push(s.size());
            }
        }

        return st.size();
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<std::string> dirs = {
            "d1/","d2/","../","d21/","./"
        };
        ASSERT_EQ(2, obj->minOperations(dirs));
    }
    {
        std::vector<std::string> dirs = {
            "d1/","d2/","./","d3/","../","d31/"
        };
        ASSERT_EQ(3, obj->minOperations(dirs));
    }
    {
        std::vector<std::string> dirs = {
            "d1/","../","../","../"
        };
        ASSERT_EQ(0, obj->minOperations(dirs));
    }
}