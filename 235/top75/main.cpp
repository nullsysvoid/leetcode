#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

using namespace binary_tree;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root)
        {
            if (p->val > root->val && q->val > root->val)
            {
                root = root->right;
            }
            else if (p->val < root->val && q->val < root->val)
            {
                root = root->left;
            }
            else
            {
                return root;
            }
        }
        return nullptr;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
}
