#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::string minRemoveToMakeValid(std::string s) {
        std::stack<int> st;

        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if(c == '(')
                st.push(i);
            else if(c == ')')
            {
                if(!st.empty())
                    st.pop();
                else
                {
                    s[i] = '#';
                }
            }
        }
        while(!st.empty())
        {
            s[st.top()] = '#';
            st.pop();
        }

        s.erase(std::remove(s.begin(), s.end(), '#'), s.end());
        return s;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {  
        ASSERT_EQ("lee(t(c)o)de", obj->minRemoveToMakeValid("lee(t(c)o)de)"));
    }
    {  
        ASSERT_EQ("ab(c)d", obj->minRemoveToMakeValid("a)b(c)d"));
    }
    {  
        ASSERT_EQ("", obj->minRemoveToMakeValid("))(("));
    }
}