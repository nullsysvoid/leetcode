#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

using namespace binary_tree;

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        std::queue<TreeNode*> q;
        std::vector<int> res;
        q.push(root);

        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len; i++)
            {
                if(i == len - 1)
                    res.push_back(q.front()->val);
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
}
