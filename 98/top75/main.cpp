#include <gtest/gtest.h>
#include <bits/stdc++.h>

 // Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    bool valid = true;
    TreeNode* prev = nullptr;

    void helper(TreeNode* root)
    {
        if(!root)
            return;
        helper(root->left);
        if(prev)
        {
            if(root->val <= prev->val)
            {
                valid = false;
                return;
            }           
        }
        prev = root;
        helper(root->right);
    }

    bool isValidBST(TreeNode* root) {
        helper(root);
        return valid;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
}
