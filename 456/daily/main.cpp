#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    bool find132pattern(std::vector<int>& nums) {
        std::stack<std::pair<int, int>> st;
        int minimum = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            while(!st.empty() && nums[i] >= st.top().first)
            {
                st.pop();
            }

            if(!st.empty() && nums[i] > st.top().second)
                return true;

            minimum = std::min(minimum, nums[i]);
            st.push({nums[i], minimum});
        }

        return false;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> nums1{1,0,1,-4,-3};
        ASSERT_FALSE(obj->find132pattern(nums1));
    }
}
