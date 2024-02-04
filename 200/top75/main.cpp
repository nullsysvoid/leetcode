#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    void helper(std::vector<std::vector<char>>& grid, int y, int x)
    {
        if(x >= 0 && x < grid[0].size() && y >= 0 && y < grid.size())
        {
            if(grid[y][x] == '1')
            {
                grid[y][x] = '0';
                helper(grid, y - 1, x);
                helper(grid, y, x - 1);
                helper(grid, y + 1, x);
                helper(grid, y, x + 1);
            }
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        int res = 0;
        for(int y = 0; y < grid.size(); y++)
        {
            for(int x = 0; x < grid[0].size(); x++)
            {
                if(grid[y][x] == '1')
                {
                    res++;
                    helper(grid, y, x);
                }
            }
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    std::vector<std::vector<char>> grid {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
    };

    EXPECT_EQ(1, obj->numIslands(grid));
}
