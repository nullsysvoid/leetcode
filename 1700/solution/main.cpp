#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        int cnt[2] = {0, 0};
        for(auto i : students)
        {
            cnt[i]++;
        }

        for(auto i : sandwiches)
        {
            cnt[i]--;
            if(cnt[i] < 0)
            {
                cnt[i] = 0;
                break;
            }
        }

        return cnt[0] + cnt[1];
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> v1{1,1,0,0};
        std::vector<int> v2{0,1,0,1};

        ASSERT_EQ(0, obj->countStudents(v1, v2));
    }
    {
        std::vector<int> v1{1,1,1,0,0,1};
        std::vector<int> v2{1,0,0,0,1,1};

        ASSERT_EQ(3, obj->countStudents(v1, v2));
    }
}
