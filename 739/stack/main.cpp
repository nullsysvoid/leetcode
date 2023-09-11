#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        std::stack<int> st;

        for(int i = temperatures.size() - 1; i >= 0; i--)
        {
            int value = temperatures[i];
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }
            if(st.empty())
                res[i] = 0;
            else
                res[i] = st.top() - i;
            st.push(i);
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {  
        std::vector<int> temperatures{73,74,75,71,69,72,76,73};
        std::vector<int> output{1,1,4,2,1,1,0,0};
        ASSERT_EQ(output, obj->dailyTemperatures(temperatures));
    }
    {  
        std::vector<int> temperatures{89,62,70,58,47,47,46,76,100,70};
        std::vector<int> output{8,1,5,4,3,2,1,1,0,0};
        ASSERT_EQ(output, obj->dailyTemperatures(temperatures));
    }
}