#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int len = 0;
        ListNode* tmp = head;
        std::unordered_map<int, ListNode*> mp;
        while(tmp)
        {
            mp[len] = tmp;
            tmp = tmp->next;
            len++;
        }

        while(left < right)
        {
            std::swap(mp[left - 1]->val, mp[right - 1]->val);
            left++;
            right--;
        }

        return head;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> v1{1,2,3,4,5};
        std::vector<int> v2{1,4,3,2,5};
        auto nodeInput = CreateLinkedList(v1);
        auto nodeOutput = CreateLinkedList(v2);

        obj->reverseBetween(nodeInput, 2, 4);
        ASSERT_TRUE(CompareLinkedLists(nodeOutput, nodeInput));
    }
    {
        std::vector<int> v1{5};
        std::vector<int> v2{5};
        auto nodeInput = CreateLinkedList(v1);
        auto nodeOutput = CreateLinkedList(v2);

        obj->reverseBetween(nodeInput, 1, 1);
        ASSERT_TRUE(CompareLinkedLists(nodeOutput, nodeInput));
    }
}
