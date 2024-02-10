#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<std::pair<char, long long>> st;
        
        long long currentSum = 0;
        char sign = 1;

        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            if(isdigit(c))
            {
                long long num = 0;
                while(i < s.size() && isdigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                currentSum += (num * sign);
                sign = 1;
            }
            else if(c == ' ')
                continue;
            else if(c == '(')
            {
                st.push({sign, currentSum});
                currentSum = 0;
                sign = 1;
            }
            else if(c == ')')
            {
                currentSum = st.top().second + currentSum * st.top().first;
                st.pop();
                sign = 1;
            }
            else if(c == '+')
            {
                sign = 1;
            }
            else if(c == '-')
            {
                sign = -1;
            }
        }

        return currentSum;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
}
