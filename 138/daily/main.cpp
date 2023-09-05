#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* head1 = head;
        Node* n = new Node(0);
        Node* top = n;
        std::unordered_map<Node*, Node*> mp;

        while(head)
        {
            Node* tmp = new Node(head->val);
            mp[head] = tmp;
            n->next = tmp;
            head = head->next;
            n = n->next;
        }

        head = head1;
        n = top->next;

        while(head)
        {
            n->random = mp[head->random];
            n = n->next;
            head = head->next;
        }

        return top->next;
    }
};


/*
TODO: testcases
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
*/