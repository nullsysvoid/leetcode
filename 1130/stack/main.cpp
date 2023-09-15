#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int mctFromLeafValues(std::vector<int>& arr) {
        int res = 0;
        std::stack<int> st;
        st.push(arr[0]);

        for (int i = 1; i < arr.size(); i++)
        {
            while (!st.empty() && st.top() <= arr[i])
            {
                int mid = st.top();
                st.pop();
                int left = !st.empty() ? st.top() : INT_MAX;
                int right = arr[i];

                res += mid * std::min(left, right);
            }
            st.push(arr[i]);
        }

        int prev = 0;
        if (!st.empty())
        {
            prev = st.top();
            st.pop();
        }
        while (st.size())
        {
            res += prev * st.top();
            prev = st.top();
            st.pop();
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> input{3,2,1,3};
        ASSERT_EQ(17, obj->mctFromLeafValues(input));
    }
    {
        std::vector<int> input{6,2,4};
        ASSERT_EQ(32, obj->mctFromLeafValues(input));
    }
}
