#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> res;

        int cur = 1;
        for(int y = 0; y < cur; y++)
        {
            std::vector<int> tmp;
            for(int x = 0; x < cur; x++)
            {
                if(x == 0 || x == cur - 1)
                    tmp.push_back(1);
                else
                    tmp.push_back(res[y-1][x] + res[y-1][x-1]);
            }
            res.push_back(tmp);
            if(cur < numRows)
                cur++;
            
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<std::vector<int>> output{
            {1},
            {1,1},
            {1,2,1},
            {1,3,3,1},
            {1,4,6,4,1}
        };
        ASSERT_EQ(output, obj->generate(5));
    }
}
