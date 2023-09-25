#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        int c = 0;
        for(int i = 0; i < s.size(); i++)
        {
            c += t[i] - s[i];
        }
        c += t[t.size() - 1];

        return c;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ('a', obj->findTheDifference("a", "aa"));
    }
}

