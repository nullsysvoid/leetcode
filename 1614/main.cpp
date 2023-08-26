#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;

int maxDepth(string s) {
    stack<char> st;

    unsigned long res = 0;

    for(auto c : s)
    {
        if(c == '(')
        {
            st.push(c);
            res = max(st.size(), res);
        }
        else if(c == ')')
            st.pop();
    }

    return res;
}

TEST(Test, Smoke) { 
    ASSERT_EQ(3, maxDepth("(1)+((2))+(((3)))"));
    ASSERT_EQ(3, maxDepth("(1+(2*3)+((8)/4))+1"));
}
