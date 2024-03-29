#pragma once
#include <bits/stdc++.h>

namespace binary_tree{
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* CreateTreePreorder(std::vector<int>& preorder);
TreeNode* CreateTreeInorder(std::vector<int>& inorder);
bool CompareTrees(TreeNode* root1, TreeNode* root2);
}

namespace n_tree{
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
}
  
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

bool CompareLinkedLists(ListNode* head1, ListNode* head2);
ListNode* CreateLinkedList(std::vector<int>& nums);
