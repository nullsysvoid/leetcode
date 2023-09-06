#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    int GetListLen(ListNode* head)
    {
        int len = 0;
        while(head)
        {
            len++;
            head = head->next;
        }
        return len;
    }

    int GetRemainder(int k, int len)
    {
        return len < k ? 0 : len % k;
    }
    
    int GetPartitionSize(int k, int len)
    {
        len /= k;
        return len > 0 ? len : 1;
    }

    std::vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = GetListLen(head);
        int rem = GetRemainder(k, len);
        int partitionSize = GetPartitionSize(k, len);

        std::vector<ListNode*> res(k, nullptr);

        for(int i = 0; i < k; i++)
        {
            ListNode* tmp = head;
            res[i] = head;
            for(int j = 0; j < partitionSize + (rem > 0) && head; j++)
            {
                if(j < partitionSize + (rem > 0) - 1)
                {
                    tmp = tmp->next;
                }
                head = head->next;
            }

            if(rem)
                rem--;
            if(tmp)
                tmp->next = nullptr;
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> v1{1,2,3,4,5,6,7,8,9,10};
        auto head = CreateLinkedList(v1);
        std::vector<ListNode*> output;

        auto vecLists = obj->splitListToParts(head, 3);

        std::vector<int> o1{1,2,3,4};
        auto out1 = CreateLinkedList(o1);

        std::vector<int> o2{5,6,7};
        auto out2 = CreateLinkedList(o2);

        std::vector<int> o3{8,9,10};
        auto out3 = CreateLinkedList(o3);

        ASSERT_TRUE(CompareLinkedLists(out1, vecLists[0]));
        ASSERT_TRUE(CompareLinkedLists(out2, vecLists[1]));
        ASSERT_TRUE(CompareLinkedLists(out3, vecLists[2]));
    }
}
