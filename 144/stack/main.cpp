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
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> st;
        std::vector<int> res;

        while(root || !st.empty())
        {
            if(root)
            {
                res.push_back(root->val);
                if(root->right)
                    st.push(root->right);
                root = root->left;
            }
            else
            {
                root = st.top();
                st.pop();
            }
        }

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
        std::vector<int> output{1,2,3};
        ASSERT_EQ(output, obj->preorderTraversal(&n1));
    }
    {
        std::vector<int> output;
        ASSERT_EQ(output, obj->preorderTraversal(nullptr));
    }
    {
        TreeNode n1(1);
        std::vector<int> output{1};
        ASSERT_EQ(output, obj->preorderTraversal(&n1));
    }
    {        
        TreeNode n2(2);
        TreeNode n3(3);
        TreeNode n4(4, &n2, nullptr);
        TreeNode n1(1, &n4, &n3);

        std::vector<int> output{1,4,2,3};
        ASSERT_EQ(output, obj->preorderTraversal(&n1));
    }
}
