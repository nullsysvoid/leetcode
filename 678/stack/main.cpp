#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    bool checkValidString(std::string s) {
        std::stack<int> st_open, st_ast;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                st_open.push(i);
            else if(s[i] == '*')
                st_ast.push(i);
            else
            {
                if(!st_open.empty())
                    st_open.pop();
                else if(!st_ast.empty())
                    st_ast.pop();
                else
                    return false;
            }
        }

        while(!st_open.empty())
        {
            if(!st_ast.empty())
            {
                if(st_open.top() > st_ast.top())
                    return false;
                st_open.pop();
                st_ast.pop();
            }
            else
                return false;
        }

        return st_open.empty();
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ(true, obj->checkValidString("()"));
    }
    {
        ASSERT_EQ(true, obj->checkValidString("(*)"));
    }
    {
        ASSERT_EQ(true, obj->checkValidString("(*))"));
    }
    {
        ASSERT_EQ(false, obj->checkValidString("(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"));
    }
    
}