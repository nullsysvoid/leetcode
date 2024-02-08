#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> st;

        for(const auto& token : tokens)
        {
            if(token.size() == 1)
            {
                if(isdigit(token[0]))
                {
                    st.push(token[0] - 0x30);
                }
                else
                {
                    int val1 = st.top();
                    st.pop();
                    int val2 = st.top();
                    st.pop();

                    switch(token[0])
                    {
                        case '+':
                            st.push(val1 + val2);
                            break;
                        case '-':
                            st.push(val2 - val1);
                            break;
                        case '*':
                            st.push(val1 * val2);
                            break;
                        case '/':
                            st.push(val2 / val1);
                            break;
                    }

                }
            }
            else
            {
                int val = std::stoi(token);
                st.push(val);
            }
        }

        return st.top();
    }
};
TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
    }
}
