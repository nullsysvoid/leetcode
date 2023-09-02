#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::string helper(const std::string& s)
    {
        std::string res;
        std::stack<char> st;
        for(auto c : s)
        {
            if(c=='#')
            {
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(c);
        }
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
    bool backspaceCompare(std::string s, std::string t) {
        return helper(s) == helper(t);       
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
        ASSERT_EQ(true, obj->backspaceCompare("ab#c", "ad#c"));
        ASSERT_EQ(true, obj->backspaceCompare("ab##", "c#d#"));
        ASSERT_EQ(false, obj->backspaceCompare("a#c", "b")); 
}