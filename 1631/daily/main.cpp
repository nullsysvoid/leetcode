#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int helper(std::vector<std::vector<int>>& array, std::vector<std::vector<int>>& dist)
    {
        int y = array.size(), x = array[0].size();
        
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> pq;
        pq.push({0,0,0});
        dist[0][0] = 0;

        while(!pq.empty())
        {
            int i = pq.top()[0];
            int j = pq.top()[1];
            int w = pq.top()[2];
            pq.pop();
            
            if(i>0 && dist[i-1][j]>std::max(w,abs(array[i][j]-array[i-1][j])) )
            {
                dist[i-1][j] = std::max(w,abs(array[i][j]-array[i-1][j]));
                pq.push({i-1,j,dist[i-1][j]});
            }
            if(i<y-1 && dist[i+1][j]>std::max(w,abs(array[i][j]-array[i+1][j])) )
            {
                dist[i+1][j] = std::max(w,abs(array[i][j]-array[i+1][j]));
                pq.push({i+1,j,dist[i+1][j]});
            }
            if(j>0 && dist[i][j-1]>std::max(w,abs(array[i][j]-array[i][j-1])) )
            {
                dist[i][j-1] = std::max(w,abs(array[i][j]-array[i][j-1]));
                pq.push({i,j-1,dist[i][j-1]});
            }
            if(j<x-1 && dist[i][j+1]>std::max(w,abs(array[i][j]-array[i][j+1])) )
            {
                dist[i][j+1] = std::max(w,abs(array[i][j]-array[i][j+1]));
                pq.push({i,j+1,dist[i][j+1]});
            }
        }
        
        return dist[y-1][x-1];
    }
    int minimumEffortPath(std::vector<std::vector<int>>& heights) {
        int y = heights.size();
        int x = heights[0].size();
        
        std::vector<std::vector<int>> dist(y, std::vector<int>(x, INT_MAX));
        return helper(heights, dist);
    }
};
TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<std::vector<int>> heights{{1,2,2},{3,8,2},{5,3,5}};
        ASSERT_EQ(2, obj->minimumEffortPath(heights));
    }
}
