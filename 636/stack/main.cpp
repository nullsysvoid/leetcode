#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs) {
        int id;
        char buf[7];
        int timestamp;

        std::stack<std::pair<int, int>> st;
        std::vector<int> res(n, 0);

        for(const auto& log : logs)
        {
            std::sscanf(log.c_str(), "%d:%[^:]:%d", &id, buf, &timestamp);
            if (buf[0] == 's')
            {
                st.push({id, timestamp});
            }
            else
            {
                int curTime = timestamp - st.top().second + 1;
                res[id] += curTime;
                st.pop();

                if(!st.empty())
                {
                    res[st.top().first] -= curTime;
                }
            }
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<std::string> input = {"0:start:0","1:start:2","1:end:5","0:end:6"};
        std::vector<int> output = {3,4};
        ASSERT_EQ(output, obj->exclusiveTime(2, input));
    }
}

