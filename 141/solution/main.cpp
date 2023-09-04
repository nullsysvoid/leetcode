#include <gtest/gtest.h>
#include <bits/stdc++.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *fast = head;
        ListNode *slow = head;

        while(fast && slow)
        {
            if(fast->next)
                fast = fast->next->next;
            else
                return false;
            if(slow)
                slow = slow->next;
            else
                return false;
            if(fast == slow)
                return true;
        }
        return false;
    }
};

ListNode* CreateLinkedList(std::vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    for (auto num : nums) {
        ListNode* newNode = new ListNode(num);
        current->next = newNode;
        current = current->next;
    }
    
    return dummy->next;
}

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> v1{3,2,0,-4};
        auto l1 = CreateLinkedList(v1);
        auto secondNode = l1->next;
        secondNode->next->next = secondNode;
        ASSERT_EQ(true, obj->hasCycle(l1));
    }
    {
        std::vector<int> v1{1,2};
        auto l1 = CreateLinkedList(v1);
        ASSERT_EQ(false, obj->hasCycle(l1));
    }
}
