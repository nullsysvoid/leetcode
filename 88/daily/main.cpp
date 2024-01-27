#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int n1 = m - 1;
        int n2 = nums2.size() - 1;
        n = n + m - 1;

        while(n1 >= 0 && n2 >= 0)
        {
            if(nums1[n1] > nums2[n2])
            {
                nums1[n] = nums1[n1];
                n1--;
            }
            else
            {
                nums1[n] = nums2[n2];
                n2--;
            }
            n--;
        }
        while(n2 >= 0)
        {
            nums1[n] = nums2[n2];
            n2--;
            n--;
        }  
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();

    {
        std::vector<int> nums1 = {1,2,3,0,0,0};
        int m = 3;
        std::vector<int> nums2 = {2,5,6};
        int n = 3;
        std::vector<int> nums3 = {1,2,2,3,5,6};
        obj->merge(nums1, m, nums2, n);
        ASSERT_EQ(nums3, nums1);
    }
    {
        std::vector<int> nums1 = {6,6,6,0,0,0};
        int m = 3;
        std::vector<int> nums2 = {0,0,0};
        int n = 3;
        std::vector<int> nums3 = {0,0,0,6,6,6};
        obj->merge(nums1, m, nums2, n);
        ASSERT_EQ(nums3, nums1);
    }
}
