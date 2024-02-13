#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int x_size;
    int y_size;
    std::set<std::pair<int, int>> st;
 
    void helper(std::vector<std::vector<int>>& grid, int x, int y)
    {
        //left
        if(x > 0 && grid[y][x - 1] == 1)
        {
            grid[y][x - 1] = 2;
            st.insert({x - 1, y});
        }
        //right
        if(x < (x_size - 1) && grid[y][x + 1] == 1)
        {
            grid[y][x + 1] = 2;
            st.insert({x + 1, y});
        }
        //down
        if(y < (y_size - 1) && grid[y + 1][x] == 1)
        {
            grid[y + 1][x] = 2;
            st.insert({x, y + 1});
        }
        //up
        if(y > 0 && grid[y - 1][x] == 1)
        {
            grid[y - 1][x] = 2;
            st.insert({x, y - 1});
        }
    }

    int orangesRotting(std::vector<std::vector<int>>& grid) {
        x_size = grid[0].size();
        y_size = grid.size();

        int res = 0;
        while(true)
        {
            int len = st.size();
            for(int y = 0; y < y_size; y++)
            {
                for(int x = 0; x < x_size; x++)
                {
                    if(grid[y][x] == 2 && st.find({x, y}) == st.end())
                    {
                        helper(grid, x, y);
                    }
                }
            }

            if(st.size() == len)
                break;
            st.clear();
            res++;
        }

        for(int y = 0; y < y_size; y++)
        {
            for(int x = 0; x < x_size; x++)
            {
                if(grid[y][x] == 1)
                {
                    return -1;
                }
            }
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<std::vector<int>> grid{
            {2,1,1},
            {1,1,0},
            {0,1,1},
        };
        EXPECT_EQ(obj->orangesRotting(grid), 4);
    }
}


/*

*/

