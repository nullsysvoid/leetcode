#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

using namespace binary_tree;

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int typeN;
        int cnt = 0;

        for(auto i : nums)
        {
            if(cnt == 0)
            {
                typeN = i;
                cnt++;
            }
            else if(typeN == i)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }

        return typeN;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
}
