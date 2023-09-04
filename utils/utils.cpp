#include "utils.h"

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
