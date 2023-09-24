#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double v[102][102] = {0};
        v[0][0] = poured;
        for(int y = 0; y <= query_row; y++)
        {
            for(int x = 0; x <= query_glass; x++)
            {
                double value = (v[y][x] - 1.0) / 2.0;
                if(value > 0)
                {
                    v[y + 1][x] += value;
                    v[y + 1][x + 1] += value;
                }
            }
        }

        return std::min(v[query_row][query_glass], 1.0);
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ(0.5, obj->champagneTower(4, 2, 1));
    }
}

