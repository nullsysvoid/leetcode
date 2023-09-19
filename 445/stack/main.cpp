#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    ListNode* add(std::stack<ListNode*>& st1, std::stack<ListNode*>& st2)
    {
        int carry = 0;
        ListNode* cur;
        while(!st1.empty() && !st2.empty())
        {
            int val = st1.top()->val + st2.top()->val + carry;
            if(val > 9)
                carry = 1;
            else
                carry = 0;
            val %= 10;

            st1.top()->val = val;
            cur = st1.top();
            st1.pop();
            st2.pop();
        }
        while(carry)
        {
            if(st1.empty())
            {
                ListNode* node = new ListNode(carry);
                node->next = cur;
                return node;
            }
            int val = st1.top()->val + carry;
            if(val > 9)
                carry = 1;
            else
                carry = 0;
            val %= 10;
            st1.top()->val = val;
            cur = st1.top();
            st1.pop();
        }

        while(!st1.empty())
        {
            st1.top();
            cur = st1.top();
            st1.pop();
        }

        return cur;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<ListNode*> st1, st2;

        while(l1)
        {
            st1.push(l1);
            l1 = l1->next;
        }
        while(l2)
        {
            st2.push(l2);
            l2 = l2->next;
        }

        if(st1.size() >= st2.size())
            return add(st1, st2);
        else
            return add(st2, st1);

        return nullptr;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> l1{9, 1, 6};
        std::vector<int> l2{0};

        ListNode* ll1 = CreateLinkedList(l1);
        ListNode* ll2 = CreateLinkedList(l2);
        ListNode* output = CreateLinkedList(l1);

        auto list = obj->addTwoNumbers(ll1, ll2);
        ASSERT_TRUE(CompareLinkedLists(list, output));
    }
    {
        std::vector<int> l1{9};
        std::vector<int> l2{1};
        std::vector<int> l3{1,0};

        ListNode* ll1 = CreateLinkedList(l1);
        ListNode* ll2 = CreateLinkedList(l2);
        ListNode* output = CreateLinkedList(l3);

        auto list = obj->addTwoNumbers(ll1, ll2);
        ASSERT_TRUE(CompareLinkedLists(list, output));
    }
    {
        std::vector<int> l1{0};
        std::vector<int> l2{0};
        std::vector<int> l3{0};

        ListNode* ll1 = CreateLinkedList(l1);
        ListNode* ll2 = CreateLinkedList(l2);
        ListNode* output = CreateLinkedList(l3);

        auto list = obj->addTwoNumbers(ll1, ll2);
        ASSERT_TRUE(CompareLinkedLists(list, output));
    }
    {
        std::vector<int> l1{2, 4, 3};
        std::vector<int> l2{5, 6, 4};
        std::vector<int> l3{8, 0, 7};

        ListNode* ll1 = CreateLinkedList(l1);
        ListNode* ll2 = CreateLinkedList(l2);
        ListNode* output = CreateLinkedList(l3);

        auto list = obj->addTwoNumbers(ll1, ll2);
        ASSERT_TRUE(CompareLinkedLists(list, output));
    }
    {
        std::vector<int> l1{7, 2, 4, 3};
        std::vector<int> l2{5, 6, 4};
        std::vector<int> l3{7, 8, 0, 7};

        ListNode* ll1 = CreateLinkedList(l1);
        ListNode* ll2 = CreateLinkedList(l2);
        ListNode* output = CreateLinkedList(l3);

        auto list = obj->addTwoNumbers(ll1, ll2);
        ASSERT_TRUE(CompareLinkedLists(list, output));
    }
}

