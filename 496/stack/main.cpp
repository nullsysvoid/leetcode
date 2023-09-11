#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> mp;
        std::stack<int> st;

        for(int i = nums2.size() - 1; i >= 0; i--)
        {
            int val = nums2[i];
            while(!st.empty() && st.top() <= val)
            {
                st.pop();
            }
            if(!st.empty())
                mp[val] = st.top();
            else
                mp[val] = -1;
            st.push(nums2[i]);
        }
        std::vector<int> res;
        for(auto i : nums1)
        {
            res.push_back(mp[i]);
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> nums1{4,1,2};
        std::vector<int> nums2{1,3,4,2};
        std::vector<int> output{-1,3,-1};     
        ASSERT_EQ(output, obj->nextGreaterElement(nums1, nums2));
    }
    {
        std::vector<int> nums1{2,4};
        std::vector<int> nums2{1,2,3,4};
        std::vector<int> output{3,-1};     
        ASSERT_EQ(output, obj->nextGreaterElement(nums1, nums2));
    }
}