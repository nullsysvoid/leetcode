#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    bool sum2(std::vector<int>& nums, int& l, int& r, int target)
    {
        while (l < r)
        {
            if (nums[l] + nums[r] == target)
            {
                return true;
            }
            else if (nums[l] + nums[r] > target)
            {
                r--;
            }
            else if (nums[l] + nums[r] < target)
            {
                l++;
            }
        }
        return false;
    }

    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int target = 0 - nums[i];
            int l = i + 1;
            int r = nums.size() - 1;
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            while(l < r && sum2(nums, l, r, target))
            {
                if(!res.empty())
                {
                    if(res.back()[0] == nums[i] && res.back()[1] == nums[l] && res.back()[2] == nums[r])
                    {                      
                    }
                    else
                    {
                        res.push_back({nums[i], nums[l], nums[r]});
                    }
                }
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                }
                l++;
                r--;
            }
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    /*{
        std::vector<int> input
        {
            -1,0,1,2,-1,-4
        };
        std::vector<std::vector<int>> output
        {
            {-1,-1,2},
            {-1,0,1},
        };
        EXPECT_EQ(output, obj->threeSum(input));
    }*/
    //[-1,0,1,2,-1,-4]
    //[0,1,1]
    //[0,0,0]
    //[0,0,0,0]
    //[-2,0,1,1,2]
    
}
