#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mp;
        vector<int> res;

        for(int i = 0; i < nums.size(); i++)
        {
            if (auto it = mp.find(target - nums[i]); it != mp.end())
            {
                res.push_back(i);
                res.push_back(it->second);
            }
            mp.insert({nums[i], i});
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
    }
}
