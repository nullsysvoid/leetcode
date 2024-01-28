#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int l = 0; 
        int r = nums.size() - 1;

        int res = 0;
        while(l <= r)
        {
            if (nums[r] == val)
            {
                r--;
            }
            else
            {
                if(nums[l] == val)
                {
                    std::swap(nums[r], nums[l]);
                    r--;
                }
                res++;
                l++;
            }
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    std::vector<int> nums{3,2,2,3};
    ASSERT_EQ(2, obj->removeElement(nums, 3));
}