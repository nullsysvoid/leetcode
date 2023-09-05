#include "utils.h"

bool CompareLinkedLists(ListNode* head1, ListNode* head2)
{
    while (head1 && head2)
    {
        if (head1->val != head2->val)
        	return false;
        
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return (!head1 && !head2);
}

ListNode* CreateLinkedList(std::vector<int>& nums)
{
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    
    for (auto num : nums) {
        ListNode* newNode = new ListNode(num);
        current->next = newNode;
        current = current->next;
    }
    
    return dummy->next;
}
