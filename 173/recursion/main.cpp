#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

using namespace binary_tree;

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
    int next() {
        return v[cur++];
    }
    
    bool hasNext() {
        return cur != v.size();
    }
private:
    void helper(TreeNode* root)
    {
        if(!root)
            return;
        helper(root->left);
        v.push_back(root->val);
        helper(root->right);
    }
    int cur = 0;
    std::vector<int> v;
};


TEST(Test, Smoke) {
    {
        std::vector input{3, 7, 9, 15, 20};
        auto root = CreateTreeInorder(input);
        std::shared_ptr<BSTIterator> bSTIterator = std::make_shared<BSTIterator>(root);


        ASSERT_EQ(3, bSTIterator->next());    // return 3
        ASSERT_EQ(7, bSTIterator->next());    // return 7
        ASSERT_TRUE(bSTIterator->hasNext());  // return True
        ASSERT_EQ(9, bSTIterator->next());    // return 9
        ASSERT_TRUE(bSTIterator->hasNext());  // return True
        ASSERT_EQ(15, bSTIterator->next());   // return 15
        ASSERT_TRUE(bSTIterator->hasNext());  // return True
        ASSERT_EQ(20, bSTIterator->next());   // return 20
        ASSERT_FALSE(bSTIterator->hasNext()); // return False
    }
}