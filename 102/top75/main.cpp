#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

using namespace binary_tree;

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        std::queue<TreeNode*> q;
        q.push(root);

        std::vector<std::vector<int>> res;
        while(!q.empty())
        {
            size_t len = q.size();

            std::vector<int> tmp;
            for(int i = 0; i < len; i++)
            {
                tmp.push_back(q.front()->val);
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            res.push_back(tmp);
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
    }
}
