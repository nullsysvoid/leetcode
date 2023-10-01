#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string res;
        std::stack<char> st;

        for(auto c : s)
        {
            if(c == ' ')
            {
                while(!st.empty())
                {
                    res += st.top();
                    st.pop();
                }

                res += ' ';
            }
            else
            {
                st.push(c);
            }
        }
        
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ("s'teL ekat edoCteeL tsetnoc", obj->reverseWords("Let's take LeetCode contest"));
    }

}
