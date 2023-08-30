#include <gtest/gtest.h>
#include <bits/stdc++.h>

// Definition for a Node.
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

class Solution {
public:
    std::vector<int> res;
    void helper(Node* root)
    {
        if(!root)
            return;
        for(const auto& child : root->children)
        {
            helper(child);
        }

        res.push_back(root->val);
    }

    std::vector<int> postorder(Node* root) {
        helper(root);
        return res;
    }
};

TEST(Test, Smoke) {
    std::vector<Node*> root(1);
    //[1,null,3,2,4,null,5,6]

    Node n2(2);
    Node n4(4);
    Node n5(5);
    Node n6(6);
    Node n3(3, {&n5, &n6});
    Node n1(1, {&n3, &n2, &n4});

    std::vector<int> output{5,6,3,2,4,1};

    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    ASSERT_EQ(output, obj->postorder(&n1));
}
