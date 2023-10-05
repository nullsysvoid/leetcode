#include <gtest/gtest.h>
#include <bits/stdc++.h>


class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        std::pair<int, int> vals[2] = {{INT_MIN, 0}, {INT_MIN, 0}};

        for(auto num : nums){
            if(num == vals[0].first)
            {
                vals[0].second++;
            }
            else if(num == vals[1].first)
            {
                vals[1].second++;
            }
            else if(vals[0].second == 0)
            {
                vals[0] = {num, 1};
            }
            else if(vals[1].second == 0)
            {
                vals[1] = {num, 1};
            }
            else{
                vals[0].second--;
                vals[1].second--;
            }
        }

        std::vector<int> res;
        int count23 = nums.size() / 3;
        vals[0].second = vals[1].second = 0;

        for(auto num : nums){
            if(num == vals[0].first)
            {
                vals[0].second++;
            }
            else if(num == vals[1].first)
            {
                vals[1].second++;
            }
        }

        if(vals[0].second > count23)
        {
            res.push_back(vals[0].first);
        }
        if(vals[1].second > count23)
        {
            res.push_back(vals[1].first);
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();

    {
        std::vector<int> input{1,2,3,1,2};
        std::vector<int> output{1,2};
        ASSERT_EQ(output, obj->majorityElement(input));
    }
    {
        std::vector<int> input{3,2,3};
        std::vector<int> output{3};
        ASSERT_EQ(output, obj->majorityElement(input));
    }
    {
        std::vector<int> input{1};
        std::vector<int> output{1};
        ASSERT_EQ(output, obj->majorityElement(input));
    }
    {
        std::vector<int> input{1,2};
        std::vector<int> output{1,2};
        ASSERT_EQ(output, obj->majorityElement(input));
    }
}
