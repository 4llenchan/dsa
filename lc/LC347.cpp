#include <gtest/gtest.h>

#include <algorithm>
#include <deque>
#include <numeric>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "Common.h"

using namespace std;


namespace lc347 {
/**
 * https://leetcode-cn.com/problems/top-k-frequent-elements/
 * 类似于桶排序进行求解，空间换时间
 */
class Solution1 {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> occurrences;
        int maxCount = 0;
        for (const int &num : nums) {
            maxCount = max(maxCount, ++occurrences[num]);
        }

        vector<vector<int>> buckets(maxCount + 1);
        for (const auto &pair : occurrences) {
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> results;
        for (int i = maxCount; i >= 0 && results.size() < k; --i) {
            for (const int &num : buckets[i]) {
                results.push_back(num);
                if (results.size() == k) {
                    break;
                }
            }
        }
        return results;
    }
};
} // namespace lc347

class LC347Tests : public ::testing::Test {
protected:
    lc347::Solution1 solution1;
};

TEST_F(LC347Tests, case1) {
    vector<int> nums{1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> expect{1, 2};
    auto result = solution1.topKFrequent(nums, k);
    EXPECT_EQ(result, expect);
}

TEST_F(LC347Tests, case2) {
    vector<int> nums{1};
    int k = 1;
    vector<int> expect{1};
    auto result = solution1.topKFrequent(nums, k);
    EXPECT_EQ(result, expect);
}