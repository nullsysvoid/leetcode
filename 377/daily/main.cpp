#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int combinationSum4(std::vector<int>& nums, int target) {
        std::vector<long long> dp(target + 1);
        dp[0] = 1;
        sort (nums.begin(), nums.end());
        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < nums.size() && i >= nums[j]; j++)
            {
                dp[i] += dp[i - nums[j]];
                if(dp[i] > INT_MAX)
                    dp[i] = INT_MAX;
            }
        }
        return dp.back();
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> nums{100,200,300};
        ASSERT_EQ(7, obj->combinationSum4(nums, 400));
    }
    {
        std::vector<int> nums{9};
        ASSERT_EQ(0, obj->combinationSum4(nums, 3));
    }
    {
        std::vector<int> nums{10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
        ASSERT_EQ(1, obj->combinationSum4(nums, 999));
    }    
}