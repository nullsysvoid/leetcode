#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

using namespace binary_tree;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
        std::stack<TreeNode*> st;

        for(int i = 0; i < nums.size(); i++)
        {
            TreeNode* node = new TreeNode(nums[i]);

            while(!st.empty() && st.top()->val < nums[i])
            {
                node->left = st.top();
                st.pop();
            }

            if(!st.empty())
            {
                st.top()->right = node;
            }

            st.push(node);
        }

        while(st.size() > 1)
            st.pop();

        return st.top();
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> v1{3,2,1,6,0,5};
        auto node = obj->constructMaximumBinaryTree(v1);
        ASSERT_EQ(node->val, 6);
    }
    {
        std::vector<int> v1{3,2,1};
        auto node = obj->constructMaximumBinaryTree(v1);
        ASSERT_EQ(node->val, 3);
    }
}
