#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int minAddToMakeValid(std::string s) {
        std::stack<char> st;
        
        for(auto c : s)
        {
            if(c == '(')
                st.push(c);
            else
            {
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(c);
            }
        }

        return st.size();
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ(1, obj->minAddToMakeValid("())"));
    }
    {
        ASSERT_EQ(3, obj->minAddToMakeValid("((("));
    }
}
