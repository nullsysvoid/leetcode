#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

using namespace binary_tree;

class Solution {
public:
    TreeNode* bstFromPreorder(std::vector<int>& preorder) {
        std::stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        TreeNode* cur = root;

        for(int i = 1; i < preorder.size(); i++)
        {
            if(cur->val > preorder[i])
            {
                cur->left = new TreeNode(preorder[i]);
                st.push(cur);
                cur = cur->left;
            }
            else
            {
                while(!st.empty() && st.top()->val < preorder[i])
                {
                    cur = st.top();
                    st.pop();
                }
                cur->right = new TreeNode(preorder[i]);
                cur = cur->right;
            }
        }

        return root;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> nums1{8,5,1,7,10,12};
        auto output = CreateTreePreorder(nums1);
        ASSERT_TRUE(CompareTrees(output, obj->bstFromPreorder(nums1)));
    }
    {
        std::vector<int> nums1{1,3};
        auto output = CreateTreePreorder(nums1);
        ASSERT_TRUE(CompareTrees(output, obj->bstFromPreorder(nums1)));
    }
}
