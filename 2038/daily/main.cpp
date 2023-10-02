#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    bool winnerOfGame(std::string colors) {
        if(colors.size() < 3)
            return false;

        char color[3] = {}; 
        int alise = 0;
        int bob = 0;

        for(int i = 0; i < colors.size(); i++)
        {
            color[0] = color[1];
            color[1] = color[2];
            color[2] = colors[i];
            if(color[0] == 'A' && color[1] == 'A' && color[2] == 'A')
            {
                alise++;
            }
            else if(color[0] == 'B' && color[1] == 'B' && color[2] == 'B')
            {
                bob++;
            }
        }
        return alise > bob;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_TRUE(obj->winnerOfGame("AAABABB"));
        ASSERT_FALSE(obj->winnerOfGame("AA"));
        ASSERT_FALSE(obj->winnerOfGame("ABBBBBBBAAA"));
        ASSERT_FALSE(obj->winnerOfGame("BBAA"));
    }
}

