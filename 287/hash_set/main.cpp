#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> st;

        for(auto i : nums)
        {
            auto it = st.find(i);
            if(it != st.end())
                return i;
            st.insert(i);
        }

        return 0;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> nums1{1,3,4,2,2};
        ASSERT_EQ(2, obj->findDuplicate(nums1));
    }
}
