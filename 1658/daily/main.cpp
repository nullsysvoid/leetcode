#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        int total = 0;
        for(auto i : nums)
            total += i;

        int target = total - x;
        int cur = 0;

        int res = INT_MIN;

        for(int l = 0, r = 0; r < nums.size(); r++)
        {
            cur += nums[r];
            while(l <= r && cur > target)
            {
                cur -= nums[l];
                l++;
            }
            if(cur == target)
            {
                res = std::max(res, r - l + 1);
            }
        }

        return res == INT_MIN ? -1 : nums.size() - res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> nums1{1,1,4,2,3};
        ASSERT_EQ(2, obj->minOperations(nums1, 5));
    }
}
