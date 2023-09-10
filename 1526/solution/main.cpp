#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    int minNumberOperations(std::vector<int>& target) {
        int res = target[0];

        int last = res;
        for(auto i : target)
        {
            if(i > last)
                res += i - last;
            last = i;
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> target{1,2,3,2,1};
        ASSERT_EQ(3, obj->minNumberOperations(target));
    }
    {
        std::vector<int> target{3,1,1,2};
        ASSERT_EQ(4, obj->minNumberOperations(target));
    }
    {
        std::vector<int> target{3,1,5,4,2};
        ASSERT_EQ(7, obj->minNumberOperations(target));
    }
}
