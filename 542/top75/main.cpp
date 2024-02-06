#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    struct Pos
    {
        int x;
        int y;

        friend Pos operator+(Pos p1, const Pos& p2)
        {
            return {p1.x + p2.x, p1.y + p2.y};
        };
    };

    int y_size;
    int x_size;

    bool isValidPos(const Pos& pos)
    {
        return (pos.x >= 0 && pos.x < x_size && pos.y < y_size && pos.y >= 0);
    }

    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
        y_size = mat.size();
        if(y_size == 0)
        {
            return mat;
        }
        std::queue<Pos> q;
        x_size = mat[0].size();

        for(int y = 0; y < y_size; y++)
        {
            for(int x = 0; x < x_size; x++)
            {
                if(mat[y][x] == 1)
                    mat[y][x] = INT_MAX;
                else
                {
                    q.push({x, y});
                }
            }
            
        }

        std::vector<Pos> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while(!q.empty())
        {
            Pos pos = q.front();
            q.pop();

            for(const auto& dir : directions)
            {
                Pos newPos = pos + dir;
                if(isValidPos(newPos))
                {
                    if(mat[newPos.y][newPos.x] > mat[pos.y][pos.x] + 1)
                    {
                        mat[newPos.y][newPos.x] = mat[pos.y][pos.x] + 1;
                        q.push(newPos);
                    }
                }
            }
        }
        return mat;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<std::vector<int>> input{
            {0,0,0},
            {0,1,0},
            {1,1,1}
        };

        std::vector<std::vector<int>> output{
            {0,0,0},
            {0,1,0},
            {1,2,1}
        };

        EXPECT_EQ(output, obj->updateMatrix(input));
    }
}

