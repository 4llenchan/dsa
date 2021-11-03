#include <gtest/gtest.h>

#include <algorithm>
#include <climits>
#include <deque>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;
namespace lc146 {
/**
 * https://leetcode-cn.com/problems/lru-cache/
 * LRU的实现
 */
class LRUCache {
public:
    explicit LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        auto it = hash_.find(key);
        if (it == hash_.end()) {
            return -1;
        }
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = hash_.find(key);
        if (it != hash_.end()) {
            it->second->second = value;
            return cache_.splice(cache_.begin(), cache_, it->second);
        }
        cache_.insert(cache_.begin(), make_pair(key, value));
        hash_[key] = cache_.begin();
        if (cache_.size() > capacity_) {
            hash_.erase(cache_.back().first);
            cache_.pop_back();
        }
    }

private:
    list<pair<int, int>> cache_;
    int capacity_;
    unordered_map<int, list<pair<int, int>>::iterator> hash_;
};
} // namespace lc146

class LC146Tests : public ::testing::Test {
};

TEST_F(LC146Tests, case1) {
    lc146::LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);
    cache.put(3, 3);
    EXPECT_EQ(cache.get(2), -1);
    cache.put(4, 4);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(3), 3);
    EXPECT_EQ(cache.get(4), 4);
}