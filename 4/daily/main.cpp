#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        if (len1 > len2)
        {
            std::swap(nums1, nums2);
            std::swap(len1, len2);
        }

        int left = 0, right = len1;
        int midTotal = (len1 + len2 + 1) / 2; // средняя точка общего массива

        while (left <= right)
        {
            int mid1 = left + (right - left) / 2; //середина первого массива
            int mid2 = midTotal - mid1; //середина второго массива

            //ищем две точки слева от середины первого массива, если такой нет то максимум или минимум
            int maxLeft1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int minRight1 = (mid1 == len1) ? INT_MAX : nums1[mid1];

            //ищем две точки справа от середины второго массива
            int maxLeft2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int minRight2 = (mid2 == len2) ? INT_MAX : nums2[mid2];

            //левая точка первого массива должна быть меньше чем правая второго массива
            //правая точка первого массива должна быть больше чем левая второго массива
            //это гарантирует что ответ посередине
            //в случае если длина четная то складываем накрест и делим на 2,
            //в случае если длина нечетная берем большее из левых величин 1 и 2 массива
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
            {
                if ((len1 + len2) % 2 == 0)
                {
                    return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
                }
                else {
                    return std::max(maxLeft1, maxLeft2);
                }
            }
            else if (maxLeft1 > minRight2)
            {
                right = mid1;
            }
            else
            {
                left = mid1 + 1;
            }
        }

        return 0.0;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> nums1{1};
        std::vector<int> nums2{1, 2, 3, 4};
        ASSERT_EQ(2, obj->findMedianSortedArrays(nums1, nums2));
    }
}
