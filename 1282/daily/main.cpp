#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes) {
        std::unordered_map<int, std::vector<int>> mp;

        for(int i = 0; i < groupSizes.size(); i++)
        {
            mp[groupSizes[i]].push_back(i);
        }

        std::vector<std::vector<int>> res;
        for(auto p : mp)
        {
            if(p.first == p.second.size())
                res.push_back(std::move(p.second));
            else
            {
                int len = p.second.size() / p.first;
                for(int j = 0; j < len; j++)
                {
                    std::vector<int> tmp;
                    int offset = j*p.first;
                    for(int i = 0; i < p.first; i++)
                    {
                        tmp.push_back(p.second[offset + i]);
                    }
                    res.push_back(std::move(tmp));
                }
            }
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<int> input{3,3,3,3,3,1,3};
        std::vector<std::vector<int>> output{
            {5},
            {0,1,2},
            {3,4,6},
        };
        auto res = obj->groupThePeople(input);
        sort(res.begin(), res.end());
        sort(output.begin(), output.end());
        ASSERT_EQ(output, res);
    }
    {
        std::vector<int> input{2,1,3,3,3,2};
        std::vector<std::vector<int>> output{
            {1},
            {0,5},
            {2,3,4}
        };
        auto res = obj->groupThePeople(input);
        sort(res.begin(), res.end());
        sort(output.begin(), output.end());
        ASSERT_EQ(output, res);
    }
}
