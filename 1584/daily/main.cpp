#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    struct Point
    {
        int distance;
        int point;

        const bool operator<(const Point& other) const
        {
            return distance > other.distance;
        }
    };

    int distance(const std::vector<int>& v1, const std::vector<int>& v2)
    {
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }
    
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        int points_cnt = points.size();
        int res = 0, i = 0;
        std::vector<bool> visited(points_cnt);
        std::priority_queue<Point> pq;

        for(int connected = 0; connected < points_cnt - 1; connected++) {
            visited[i] = true;
            for (int j = 0; j < points_cnt; ++j)
            {
                if (!visited[j])
                {
                    int dist = distance(points[i], points[j]);
                    pq.push({dist, j});
                }
            }
            while (visited[pq.top().point])
                pq.pop();
            res += pq.top().distance;
            i = pq.top().point;
            pq.pop();
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<std::vector<int>> input{
            {0,0},{2,2},{3,10},{5,2},{7,0}
        };
        ASSERT_EQ(20, obj->minCostConnectPoints(input));
    }
    {
        std::vector<std::vector<int>> input{
            {3,12},{-2,5},{-4,1}
        };
        ASSERT_EQ(18, obj->minCostConnectPoints(input));
    }
}
