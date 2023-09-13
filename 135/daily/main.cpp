#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        std::vector<int> res(ratings.size(), 1);
        int result = 0;
        for(int i = 1; i < res.size(); i++)
        {
            if(ratings[i] > ratings[i - 1])
                res[i] = res[i - 1] + 1;
        }
        for(int i = res.size() - 1; i > 0; i--)
        {
            if(ratings[i] < ratings[i - 1])
                res[i - 1] = std::max(res[i] + 1, res[i - 1]);
            result += res[i];
        }
        result += res[0];

        return result;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> nums1{1,2,2};
        ASSERT_EQ(4, obj->candy(nums1));
    }
    {
        std::vector<int> nums1{1,0,2};
        ASSERT_EQ(5, obj->candy(nums1));
    }
}
