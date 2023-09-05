#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    void reorderList(ListNode* head) {
        std::stack<ListNode*> st;
        
        int i = 0;
        ListNode* tmp = head;
        while(tmp)
        {
            st.push(tmp);
            tmp = tmp->next;
            i++;
        }

        tmp = head;
        for(int j = 0; j < i / 2; j++)
        {
            ListNode* nodeNext = tmp->next;
            tmp->next = st.top();
            st.pop();
            tmp->next->next = nodeNext;
            tmp = nodeNext;
        }
        tmp->next = nullptr;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> v1{1,2,3,4};
        std::vector<int> v2{1,4,2,3};
        auto nodeInput = CreateLinkedList(v1);
        auto nodeOutput = CreateLinkedList(v2);

        obj->reorderList(nodeInput);
        ASSERT_TRUE(CompareLinkedLists(nodeOutput, nodeInput));
    }
    {
        std::vector<int> v1{1,2,3,4,5};
        std::vector<int> v2{1,5,2,4,3};
        auto nodeInput = CreateLinkedList(v1);
        auto nodeOutput = CreateLinkedList(v2);

        obj->reorderList(nodeInput);
        ASSERT_TRUE(CompareLinkedLists(nodeOutput, nodeInput));
    }
}
