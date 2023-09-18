#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

using namespace binary_tree;

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        std::stack<TreeNode*> st;
        TreeNode* cur = root;
        st.push(cur);

        while(!st.empty())
        {
            cur = st.top();
            st.pop();

            if(cur->right)
                st.push(cur->right);
            if(cur->left)
                st.push(cur->left);
            if(!st.empty())
                cur->right = st.top();
            cur->left = nullptr;
        }
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> nums1{2,6,7,3,1,7};
        TreeNode* node = CreateTreePreorder(nums1);
        TreeNode* output = CreateTreePreorder(nums1);
        ASSERT_TRUE(CompareTrees(output, node));
    }
}
