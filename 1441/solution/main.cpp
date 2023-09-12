#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::string> buildArray(std::vector<int>& target, int n) {
        std::vector<std::string> res;

        int cnt = 1;
        for(auto i : target)
        {            
            while(cnt < i)
            {
                cnt++;
                res.push_back("Push");
                res.push_back("Pop");
            }
            res.push_back("Push");
            cnt++;
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> v{1,3};
        std::vector<std::string> output{"Push","Push","Pop","Push"};
        ASSERT_EQ(output, obj->buildArray(v, 3));
    }
    {
        std::vector<int> v{1,2,3};
        std::vector<std::string> output{"Push","Push","Push"};
        ASSERT_EQ(output, obj->buildArray(v, 3));
    }
    {
        std::vector<int> v{1,2};
        std::vector<std::string> output{"Push","Push"};
        ASSERT_EQ(output, obj->buildArray(v, 3));
    }
}
