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
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> st;

        if(root)
            st.push(root);

        std::vector<int> res;
        while(!st.empty())
        {
            const auto top = st.top();
            st.pop();

            res.push_back(top->val);
            if(top->left)
                st.push(top->left);
            if(top->right)
                st.push(top->right);           
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        //[1,null,2,3]
        TreeNode n3(3);
        TreeNode n2(2, &n3, nullptr);
        TreeNode n1(1, nullptr, &n2);
        std::vector<int> output{3,2,1};
        ASSERT_EQ(output, obj->postorderTraversal(&n1));
    }
    {
        std::vector<int> output;
        ASSERT_EQ(output, obj->postorderTraversal(nullptr));
    }
    {
        TreeNode n1(1);
        std::vector<int> output{1};
        ASSERT_EQ(output, obj->postorderTraversal(&n1));
    }
    {        
        TreeNode n2(2);
        TreeNode n3(3);
        TreeNode n4(4, &n2, nullptr);
        TreeNode n1(1, &n4, &n3);

        std::vector<int> output{2,4,3,1};
        ASSERT_EQ(output, obj->postorderTraversal(&n1));
    }
}