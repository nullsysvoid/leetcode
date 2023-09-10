#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    bool canBeValid(std::string s, std::string locked) {
        
        std::stack<int> stOpen;
        std::stack<int> stAny;

        for(int i = 0; i < s.size(); i++)
        {
            if(locked[i] == '1')
            {
                if(s[i] == ')')
                {
                    if(!stOpen.empty())
                        stOpen.pop();
                    else if(!stAny.empty())
                        stAny.pop();
                    else
                        return false;
                }
                else
                {
                    stOpen.push(i);
                }           
            }
            else
            {
                stAny.push(i);
            }
        }

        while(!stOpen.empty() && !stAny.empty())
        {
            if(stOpen.top() < stAny.top())
            {
                stOpen.pop();
                stAny.pop();
            }
            else
            {
                return false;
            }
        }
        if(!stOpen.empty())
            return false;

        return stAny.size() % 2 == 0;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_TRUE(obj->canBeValid("())()))()(()(((())(()()))))((((()())(())", "1011101100010001001011000000110010100101"));
        ASSERT_TRUE(obj->canBeValid("()))(()(()()()()(((())())((()((())", "1100000000000010000100001000001101"));
    }
}
