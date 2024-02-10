#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils/utils.h>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        if(nums.size() > 2)
        {
            if(*nums.begin() > nums.back())
            {
                int l = 0;
                int r = nums.size();

                //0,1,2
                while(l <= r)
                {
                    int mid = (l + r) / 2;
                    int mid_value = nums[mid];

                    if(mid_value == target)
                        return mid;

                    if(mid_value > nums.back())
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;    
                    }

                }
                if(target >= nums[0] && target <= nums[l - 1])
                {
                    auto lower = std::lower_bound(nums.begin(), nums.begin() + l, target);
                    return *lower == target ? lower - nums.begin() : -1;
                }
                else if(target >= nums[l] && target <= nums[nums.size() - 1])
                {
                    auto lower = std::lower_bound(nums.begin() + l, nums.end(), target);
                    return *lower == target ? lower - nums.begin() : -1;
                }
                return -1;
            }
            else
            {
                auto lower = std::lower_bound(nums.begin(), nums.end(), target);
                return *lower == target ? lower - nums.begin() : -1;
            }
        }

        if(nums.size() == 2)
        {
            if(nums[0] == target)
                return 0;
            else if(nums[1] == target)
                return 1;
            return -1;
        }

        return nums[0] == target ? 0 : -1;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> input{4,5,6,7,0,1,2};
        ASSERT_EQ(4, obj->search(input, 0));
    }
    {
        std::vector<int> input{4,5,6,7,0,1,2};
        ASSERT_EQ(-1, obj->search(input, 3));
    }
    {
        std::vector<int> input{1,3,5};
        ASSERT_EQ(-1, obj->search(input, 0));
    }
    

}
