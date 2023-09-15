#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head)
            return nullptr;

        ListNode* cur = head;
        std::stack<ListNode*> st;
        while(cur)
        {
            while(!st.empty() && st.top()->val < cur->val)
            {
                st.pop();
            }
            st.push(cur);
            cur = cur->next;
        }

        cur = st.top();
        st.pop();
        cur->next = nullptr;

        while(!st.empty())
        {
            st.top()->next = cur;
            cur = st.top();
            st.pop();
        }

        return cur;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> nums1{5,2,13,3,8};
        auto input = CreateLinkedList(nums1);

        std::vector<int> nums2{13,8};
        auto output = CreateLinkedList(nums2);

        auto result = obj->removeNodes(input);
        ASSERT_TRUE(CompareLinkedLists(output, result));
    }
}
