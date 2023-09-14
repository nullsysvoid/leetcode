#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string seq) {
        std::vector<int> res(seq.size(), 0);
        int lvl = 0;
        for (int i = 0; i < seq.size(); i++)
        {
            if (seq[i] == '(')
            {
                lvl++;
            }
            res[i] = lvl & 1;
            if (seq[i] == ')')
            {
                lvl--;
            }
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> output{1,1,1,0,0,1,1,1};
        ASSERT_EQ(output, obj->maxDepthAfterSplit("()(())()"));
    }
    {
        std::vector<int> output{1,0,1,1,0,1};
        ASSERT_EQ(output, obj->maxDepthAfterSplit("((()))"));
    }
}
