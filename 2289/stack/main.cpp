#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int totalSteps(std::vector<int>& nums) {
        std::stack<std::pair<int,int>> st;
        int res = 0;  

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            int val = nums[i];
            if(st.empty())
                st.push({val, 0});
            else
            {
                if(val > st.top().first)
                {
                    int tmp = 0;
                    while(!st.empty() && val > st.top().first)
                    {
                        if(st.top().second > tmp)
                            tmp = st.top().second;
                        else
                            tmp++;
                        st.pop();
                    }
                    res = std::max(res, tmp);
                    st.push({val, tmp});
                }
                else
                    st.push({val, 0});
            }
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> nums = {
            5,3,4,4,7,3,6,11,8,5,11
        };
        ASSERT_EQ(3, obj->totalSteps(nums));
    }
    {
        std::vector<int> nums = {
            4,5,7,7,13
        };
        ASSERT_EQ(0, obj->totalSteps(nums));
    }
    {
        std::vector<int> nums = {
            10,1,2,3,4,5,6,1,2,3
        };
        ASSERT_EQ(6, obj->totalSteps(nums));
    }
    {
        std::vector<int> nums = {
            7,14,4,14,13,2,6,13
        };
        ASSERT_EQ(3, obj->totalSteps(nums));
    }
}