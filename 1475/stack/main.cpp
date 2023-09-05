#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> finalPrices(std::vector<int>& prices) {
        std::stack<int> st;

        for(int i = prices.size() - 1; i >= 0; i--)
        {
            while(!st.empty() && st.top() > prices[i])
                st.pop();
            
            int val = prices[i];
            if(!st.empty())
                prices[i] -= st.top();
            
            st.push(val);
        }

        return prices;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> input{8,4,6,2,3};
        std::vector<int> output{4,2,4,2,3};
        ASSERT_EQ(output, obj->finalPrices(input));
    }
    {
        std::vector<int> input{1,2,3,4,5};
        std::vector<int> output{1,2,3,4,5};
        ASSERT_EQ(output, obj->finalPrices(input));
    }
    {

        std::vector<int> input{10,1,1,6};
        std::vector<int> output{9,0,1,6};
        ASSERT_EQ(output, obj->finalPrices(input));
    }
}
