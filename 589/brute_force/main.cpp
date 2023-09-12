#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

using namespace n_tree;

class Solution {
public:
    std::vector<int> preorder(Node* root) {
        std::stack<Node*> st;
        if(!root)
            return {};
        st.push(root);
        std::vector<int> res;
        while(!st.empty())
        {
            auto node = st.top();
            res.push_back(node->val);
            st.pop();

            for(int i = node->children.size() - 1; i >= 0; i--)
            {
                st.push(node->children[i]);
            }
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> output{1,3,2,4};

        Node n3(3);
        Node n2(2);
        Node n4(4);
        std::vector<Node*> input{&n3, &n2, &n4};

        Node n1(1, input);
        ASSERT_EQ(output, obj->preorder(&n1));
    }
}
