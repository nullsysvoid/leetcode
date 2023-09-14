#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> v(m, std::vector<int>(n, 1));
        for(int y = 1; y < m; y++)
        {
            for(int x = 1; x < n; x++)
            {
                v[y][x] = v[y - 1][x] + v[y][x - 1];
            }
        }

        return v[m - 1][n - 1];
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ(28, obj->uniquePaths(3, 7));
        ASSERT_EQ(3, obj->uniquePaths(3, 2));
    }
}
