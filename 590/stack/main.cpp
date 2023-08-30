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
    std::vector<int> postorder(Node* root) {
        std::stack<Node*> st;
        std::vector<int> res;

        st.push(root);
        while (!st.empty())
        {
            const auto nodes = st.top();
            st.pop();
            res.push_back(nodes->val);

            for(const auto& node : nodes->children)
            {
                st.push(node);
            }   
        }
        reverse(res.begin(), res.end());
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
