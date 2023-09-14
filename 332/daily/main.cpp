#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils.h>

using namespace binary_tree;

class Solution {
public:
    void helper(const std::string& city)
    {
        while(mp[city].size())
        {
            auto it = mp[city].begin();
            const auto nextCity = *it;
            mp[city].erase(it);
            helper(nextCity);
        }
        res.push_back(city);
    }

    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        for(const auto& ticket : tickets)
        {
            mp[ticket[0]].insert(ticket[1]);
        }

        helper("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
private:
    std::map<std::string, std::multiset<std::string>> mp;
    std::vector<std::string> res;
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<std::vector<std::string>> input{{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
        std::vector<std::string> output{"JFK","ATL","JFK","SFO","ATL","SFO"};
        ASSERT_EQ(output, obj->findItinerary(input));
    }
}
