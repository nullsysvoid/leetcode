#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    int pairSum(ListNode* head) {
        std::vector<int> v;
        while(head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        int max_val = INT_MIN;
        for(int i = 0; i < v.size() / 2; i++)
        {
            int tmp = v[i] + v[v.size() - 1 - i];
            max_val = std::max(max_val, tmp);
        }

        return max_val;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr obj = std::make_shared<Solution>();
    {
        std::vector v1{5,4,2,1};
        auto input = CreateLinkedList(v1);
        ASSERT_EQ(6, obj->pairSum(input));
    }
    {
        std::vector v1{4,2,2,3};
        auto input = CreateLinkedList(v1);
        ASSERT_EQ(7, obj->pairSum(input));
    }
}
