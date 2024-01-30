#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* res = new ListNode();
        ListNode* res2 = res;

        while(list1 && list2)
        {
            if(list1->val > list2->val)
            {
                res->next = list2;
                list2 = list2->next;
            }
            else
            {
                res->next = list1;
                list1 = list1->next;
            }
            res = res->next;
        }
        if(list1)
        {
            res->next = list1;
        }
        else
        {
            res->next = list2;
        }

        return res2->next;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();

    std::vector<int> nums{1,1,2,3,4,4};
    ListNode* l3 = CreateLinkedList(nums);

    std::vector<int> n1{1,2,4};
    ListNode* l1 = CreateLinkedList(n1);

    std::vector<int> n2{1,3,4};
    ListNode* l2 = CreateLinkedList(n2);

    ListNode* l = obj->mergeTwoLists(l1, l2);

    ASSERT_TRUE(CompareLinkedLists(l1, l));

}