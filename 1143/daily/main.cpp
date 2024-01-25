#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int y_size = text1.size() + 1;
        int x_size = text2.size() + 1;

        std::vector<std::vector<int>> dp(y_size, std::vector<int>(x_size, 0));
    
        for(int i = 1; i < y_size; i++)
        {
            for(int j = 1; j < x_size; j++)
            {
                if(text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[y_size - 1][x_size - 1];
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ(0, obj->longestCommonSubsequence("abc", "def"));
    }

    {
        ASSERT_EQ(0, obj->longestCommonSubsequence("abc", "abc"));
    }

    {
        ASSERT_EQ(0, obj->longestCommonSubsequence("abcde", "ace"));
    }
}
