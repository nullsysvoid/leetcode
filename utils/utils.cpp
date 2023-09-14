#include "utils.h"

namespace binary_tree{
namespace{
TreeNode * helper(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin == end) {
        return nullptr;
    }
    
    auto node = new TreeNode(*begin);
    auto right = upper_bound(begin + 1, end, *begin);
    
    node->left = helper(begin + 1, right);
    node->right = helper(right, end);
    return node;
}
}

TreeNode* CreateTreePreorder(std::vector<int>& preorder) 
{
    return helper(preorder.begin(), preorder.end());
}

bool CompareTrees(TreeNode* root1, TreeNode* root2)
{
    if (!root1 && !root2)
        return true;
    
    else if (!root1 || !root2)
        return false;
    else 
    {
        if (root1->val == root2->val)
        { 
            if(CompareTrees(root1->left, root2->left) && CompareTrees(root1->right, root2->right))
            {
                return true;
            }
        }
    }
    return false;
}
}

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
