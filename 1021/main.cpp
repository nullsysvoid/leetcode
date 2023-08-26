#include <gtest/gtest.h>
#include <bits/stdc++.h>

std::string removeOuterParentheses(std::string s) {
    
    std::string res;
    std::stack<char> st;

    for(auto c : s)
    {
        if(c == '(')
        {
            st.push(c);
            if(st.size() > 1)
                res += c;
        }
        else
        {
            st.pop();
            if(st.size() >= 1)
                res += c;
        }

    }
    return res;
}

TEST(Test, Smoke) {
    std::vector<std::pair<std::string, std::string>> testcases = { 
        { "(()())(())", "()()()" },
        { "(()())(())(()(()))", "()()()()(())" },
        { "()()", "" },

    };

    for(const auto& [input, output] : testcases)
    {
        ASSERT_EQ(output, removeOuterParentheses(input));
    }  
}
