#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::stack<ListNode*> st;
        ListNode* top = head;
        int size = 0;

        while(head)
        {
            st.push(head);
            head = head->next;
            size++;
        }

        for(int i = 0; i < size / 2; i++)
        {
            if(top->val != st.top()->val)
                return false;

            st.pop();
            top = top->next;
        }

        return true;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> v1{1,2,2,1};
        auto n = CreateLinkedList(v1);
        ASSERT_EQ(true, obj->isPalindrome(n));
    }
    {
        std::vector<int> v1{1,2};
        auto n = CreateLinkedList(v1);
        ASSERT_EQ(false, obj->isPalindrome(n));
    }
}
