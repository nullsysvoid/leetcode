#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::string res;
        std::stack<std::string> st;

        for(int i = 0; i < path.size(); i++)
        {
            char c = path[i];
            if(c != '/')
            {
                std::string folder;
                while(i < path.size() && path[i] != '/')
                {
                    folder += path[i];
                    i++;
                }
                if(folder != ".")
                    st.push(folder);
            }
        }

        int cnt = 0;
        while(!st.empty())
        {
            if(st.top() == "..")
            {
                cnt++;
            }
            else
            {
                if(!cnt)
                {
                    res = st.top() + "/" + res;
                }
                else
                    cnt--;
            }
            st.pop();
        }

        if(res.size() > 1)
            res.pop_back();
        
        res = "/" + res;

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    ASSERT_EQ("/home", obj->simplifyPath("/home/"));
    ASSERT_EQ("/", obj->simplifyPath("/../"));
    ASSERT_EQ("/home/foo", obj->simplifyPath("/home//foo/"));
    ASSERT_EQ("/...", obj->simplifyPath("/.../"));
    ASSERT_EQ("/c", obj->simplifyPath("/a/./b/../../c/"));
    ASSERT_EQ("/is/here", obj->simplifyPath("/home/of/foo/../../bar/../../is/./here/."));
}
