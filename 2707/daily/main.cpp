#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        int dp[51] = {};

        for (int i = s.size() - 1; i >= 0; i--)
        {
            dp[i] = 1 + dp[i + 1];
            
            for (const auto &word : dictionary)
            {
                int word_len = i + word.size();
                if (word_len <= s.size())
                { 
                    if (s.compare(i, word.size(), word) == 0)
                    {
                        dp[i] = std::min(dp[i], dp[word_len]);
                    }
                }
            }
        }
        
        return dp[0];
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<std::string> dictionary = {"leet","code","leetcode"};
        ASSERT_EQ(2, obj->minExtraChar("leetscodee", dictionary));
    }
}

