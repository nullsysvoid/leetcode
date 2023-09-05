#pragma once
#include <bits/stdc++.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool CompareLinkedLists(ListNode* head1, ListNode* head2);
ListNode* CreateLinkedList(std::vector<int>& nums);
