#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    long long maxSum(std::vector<int>& nums, int m, int k) {

        long long currentSum = 0;
    
        std::unordered_map<int, int> mp;
        std::queue<int> window;

        std::multiset<long long> results;

        for(int i = 0; i < k; i++)
        {
            int val = nums[i];
            window.push(val);
            mp[val]++;
            currentSum += val;

            if(mp.size() >= m)
                results.insert(currentSum);
        }
            
        for(int i = k; i < nums.size(); i++)
        {
            int val = nums[i];
            currentSum -= window.front();
            currentSum += val;
            window.push(val);
            if(mp[window.front()] == 1)
                mp.erase(window.front());
            else
                mp[window.front()]--;
            
            mp[val]++;
            if(mp.size() >= m)
                results.insert(currentSum);

            window.pop();
        }

        return results.size() ? *results.rbegin() : 0;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
        {
            std::vector<int> nums1{2,6,7,3,1,7};
            ASSERT_EQ(18, obj->maxSum(nums1, 3, 4));
        }
        {
            std::vector<int> nums1{5,9,9,2,4,5,4};
            ASSERT_EQ(23, obj->maxSum(nums1, 1, 3));
        }
        {
            std::vector<int> nums1{1,2,1,2,1,2,1};
            ASSERT_EQ(0, obj->maxSum(nums1, 3, 3));
        }
        {
            std::vector<int> nums1{1,2,2,3};
            ASSERT_EQ(0, obj->maxSum(nums1, 3, 3));
        }
        {
            std::vector<int> nums1{1,1,1,3};
            ASSERT_EQ(4, obj->maxSum(nums1, 2, 2));
        }
}
