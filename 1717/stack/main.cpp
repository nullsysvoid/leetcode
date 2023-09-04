#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::string helper(const std::string& input, char a, char b)
    {
        std::string res;
        for(auto c : input)
        {
            if(res.size() && res.back() == a && c == b)
            {
                res.pop_back();
            }
            else
            {
                res += c;
            }
        }

        return res;
    }

    int getABcounts(const std::string fullString, const std::string woABString)
    {
        return (fullString.size() - woABString.size())/2;
    }

    int maximumGain(std::string s, int x, int y) {
        int res = 0;
        std::string s1, s2;
        if(x > y)
        {
            s1 = helper(s, 'a', 'b');
            s2 = helper(s1, 'b', 'a');
            res = getABcounts(s, s1)*x + getABcounts(s1, s2)*y;
        }
        else
        {
            s1 = helper(s, 'b', 'a');
            s2 = helper(s1, 'a', 'b');
            res = getABcounts(s, s1)*y + getABcounts(s1, s2)*x;
        }

        return res; 
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
        ASSERT_EQ(19, obj->maximumGain("cdbcbbaaabab", 4, 5));
        ASSERT_EQ(20, obj->maximumGain("aabbaaxybbaabb", 5, 4));   
}