#include "utils.h"

namespace binary_tree{
namespace{

TreeNode* helperPre(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin == end) {
        return nullptr;
    }
    
    auto node = new TreeNode(*begin);
    auto right = upper_bound(begin + 1, end, *begin);
    
    node->left = helperPre(begin + 1, right);
    node->right = helperPre(right, end);
    return node;
}

TreeNode* helperInorder(std::vector<int>& v, int l, int r)
{
	if(l > r)
    {
	    return nullptr;
	}

	int m = (l+r)/2;
	TreeNode* root = new TreeNode(v[m]);

	root->left = helperInorder(v, l, m - 1);
	root-> right = helperInorder(v, m + 1, r);
	return root;
}

} //namespace

TreeNode* CreateTreeInorder(std::vector<int>& inorder)
{
	return helperInorder(inorder, 0, inorder.size() - 1);
}

TreeNode* CreateTreePreorder(std::vector<int>& preorder) 
{
    return helperPre(preorder.begin(), preorder.end());
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
