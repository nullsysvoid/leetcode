#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

using namespace binary_tree;

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> l(nums.size(), 1);
        std::vector<int> r(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++)
        {
            l[i] = l[i - 1] * nums[i - 1];
        }

        for(int i = nums.size() - 2; i >= 0; i--)
        {
            r[i] = r[i + 1] * nums[i + 1];
        }

        std::vector<int> res(nums.size(), 1);

        for(int i = 0; i < nums.size(); i++)
        {
            res[i] = l[i] * r[i];
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
}
