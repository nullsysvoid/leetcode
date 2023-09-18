#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> kWeakestRows(std::vector<std::vector<int>>& mat, int k) {
        int n = mat[0].size();
        for(int i = 0; i < mat.size(); i++)
            mat[i].push_back(i);

        sort(mat.begin(), mat.end());

        std::vector<int> res(k);
        for(int i = 0; i < k; i++)
            res[i] = mat[i][n];

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<std::vector<int>> nums1{
            {1,1,0,0,0},
            {1,1,1,1,0},
            {1,0,0,0,0},
            {1,1,0,0,0},
            {1,1,1,1,1}
        };
        std::vector<int> output{2,0,3};
        ASSERT_EQ(output, obj->kWeakestRows(nums1, 3));
    }
}
