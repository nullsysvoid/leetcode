#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::stack<char> st;
        for(auto c : num)
        {
            while(!st.empty() && k && st.top() > c)
            {
                k--;
                st.pop();
            }
            if(st.empty() && c == '0')
                continue;
            st.push(c);
        }

        while(!st.empty() && k)
        {
            st.pop();
            k--;
        }
        if(st.empty())
            return "0";
        
        std::string res;
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ("1219", obj->removeKdigits("1432219", 3));
    }
    {
        ASSERT_EQ("200", obj->removeKdigits("10200", 1));
    }
    {
        ASSERT_EQ("0", obj->removeKdigits("10", 2));
    }
    {
        ASSERT_EQ("0", obj->removeKdigits("1234567890", 9));
    }
}
