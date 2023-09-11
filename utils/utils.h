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
}
  
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool CompareLinkedLists(ListNode* head1, ListNode* head2);
ListNode* CreateLinkedList(std::vector<int>& nums);
