#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {

        std::priority_queue<std::vector<int>> maxPt;
        for(const auto& pt : points)
        {
            int distance = pow(pt[0], 2) + pow(pt[1], 2);
            maxPt.push({distance, pt[0], pt[1]});
            if(maxPt.size() > k)
                maxPt.pop(); 
        }

        std::vector<std::vector<int>> res;
        while(!maxPt.empty())
        {
            res.push_back({maxPt.top()[1], maxPt.top()[2]});
            maxPt.pop();
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
    }
}

