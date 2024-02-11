#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int sign = 1;
        long long int res = 0;

        while(s[i] == ' ')
            i++;

        if(s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if(s[i] == '+')
        {
            i++;
        }

        while(i < s.size() && s[i] == '0')
        {
            i++;
        }

        while(i < s.size())
        {
            if(isdigit(s[i]))
            {
                res = res * 10 + (s[i] - '0');
                if(res > INT_MAX)
                    break;
            }
            else
                break;
            i++;
        }

        res *= sign;

        if(res > INT_MAX)
            res = INT_MAX;
        if(res < INT_MIN)
            res = INT_MIN;

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ(2147483647, obj->myAtoi("20000000000000000000"));
        ASSERT_EQ(1, obj->myAtoi("+1"));
        ASSERT_EQ(4193, obj->myAtoi("4193 with words 4"));
        ASSERT_EQ(4193, obj->myAtoi("4193 with words"));
        ASSERT_EQ(-42, obj->myAtoi("   -42"));
        ASSERT_EQ(42, obj->myAtoi("42"));
    }
}
