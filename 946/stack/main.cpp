#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
        std::stack<int> st;
        int pop_ind = 0;

        for(int i = 0; i < pushed.size(); i++)
        {
            st.push(pushed[i]);
            while(!st.empty() && popped[pop_ind] == st.top())
            {
                st.pop();
                pop_ind++;
            }
        }

        return pop_ind == popped.size();
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> pushed{1,2,3,4,5};
        std::vector<int> popped{4,5,3,2,1};
        ASSERT_TRUE(obj->validateStackSequences(pushed, popped));
    }
    {
        std::vector<int> pushed{1,2,3,4,5};
        std::vector<int> popped{4,3,5,1,2};
        ASSERT_FALSE(obj->validateStackSequences(pushed, popped));
    }
}
