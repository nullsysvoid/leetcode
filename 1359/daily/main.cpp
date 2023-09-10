#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int countOrders(int n) {
        const int mod = 1e9+7;

        long long res = 1;
        for(int i = 2; i <= n; i++)
        {
            int cnt = (2 * i - 1) * i;
            res = (res * cnt) % mod;
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    ASSERT_EQ(1, obj->countOrders(1));
    ASSERT_EQ(6, obj->countOrders(2));
}