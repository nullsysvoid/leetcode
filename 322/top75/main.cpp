#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:

    int coinChange(std::vector<int>& coins, int amount) {
        int dp[amount + 1];
        dp[0] = 0;

        sort(coins.begin(), coins.end());
        for(int i = 1; i <= amount; i++)
        {
            dp[i] = INT_MAX;
            for(auto coin : coins)
            {
                if(coin > i)
                    break;
                int currentAmount = i - coin;
                if(dp[currentAmount] != INT_MAX)
                {
                    dp[i] = std::min(dp[i], dp[currentAmount] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();

    std::vector<int> coins {186,419,83,408};
    EXPECT_EQ(obj->coinChange(coins, 6249), 20);
}