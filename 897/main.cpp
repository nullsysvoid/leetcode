#include <gtest/gtest.h>
#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    bool isSameTree(const TreeNode* p, const TreeNode* q) const {
        if (p == nullptr && q != nullptr)
            return false;
        if (p != nullptr && q == nullptr)
            return false;
        if (p == nullptr && q == nullptr)
            return true;

        if(p->val != q->val)
            return false;
        if(!isSameTree(p->left, q->left))
            return false;
        if(!isSameTree(p->right, q->right))
            return false;

        return true;
    }

    bool operator==(const TreeNode* other) const
    {
        return isSameTree(this, other);
    }
};
  
TreeNode* increasingBST(TreeNode* root) {
    TreeNode* result = new TreeNode(0);
    TreeNode* top = result;

    TreeNode* current = root;
    std::stack<TreeNode*> st;
    
    while(current || !st.empty())
    {
        if(current)
        {
            st.push(current);
            current = current->left;
        }
        else
        {
            current = st.top();
            st.pop();

            result->right = current;
            result->left = nullptr;               
            result = result->right;

            current = current->right;
        }
    }

    result->left = nullptr;
    result->right = nullptr;

    return top->right;
}

TEST(Test, Smoke) {
    TreeNode t1(1);
    TreeNode t2(2);

    TreeNode input(2, &t1, nullptr);
    
    TreeNode test(1);
    test.left = nullptr;
    test.right = &t2;

    ASSERT_EQ(test, increasingBST(&input));
}
