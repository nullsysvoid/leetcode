#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    long long subArrayRanges(std::vector<int>& nums) {
        long long res = 0;
        int max_val, min_val;
        for(int i = nums.size() - 1; i > 0; i--)
        {
            max_val = min_val = nums[i];
            for(int j = i - 1; j >= 0; j--)
            {
                max_val = std::max(max_val, nums[j]);
                min_val = std::min(min_val, nums[j]);

                res += (max_val - min_val);
            }
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> v{-2, -3, 3};
        ASSERT_EQ(13, obj->subArrayRanges(v));
    }
    {
        std::vector<int> v{4,-2,-3,4,1};
        ASSERT_EQ(59, obj->subArrayRanges(v));
    }
}
