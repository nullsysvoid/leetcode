#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> res(n, -1);
        std::stack<int> st;

        for (int i = 0; i < n * 2; ++i)
        {
            int index = i % n;
            while (!st.empty() && nums[st.top()] < nums[index])
            {
                res[st.top()] = nums[index];
                st.pop();
            }
            st.push(index);
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> input{1,2,1};
        std::vector<int> output{2,-1,2};
        ASSERT_EQ(output, obj->nextGreaterElements(input));
    }
}

