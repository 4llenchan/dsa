#include <gtest/gtest.h>

#include <vector>

#include "Algorithm.h"
#include "Common.h"

using namespace std;

class AlgorithmTests : public ::testing::TestWithParam<vector<int>> {
};

TEST_P(AlgorithmTests, quickSort) {
    vector<int> nums = GetParam();
    Algorithm::quickSort(nums);
    EXPECT_TRUE(Utils::isOrderly(nums, true));
}

TEST_P(AlgorithmTests, mergeSort) {
    vector<int> nums = GetParam();
    Algorithm::mergeSort(nums);
    EXPECT_TRUE(Utils::isOrderly(nums, true));
}

TEST_P(AlgorithmTests, insertSort) {
    vector<int> nums = GetParam();
    Algorithm::insertSort(nums);
    EXPECT_TRUE(Utils::isOrderly(nums, true));
}

TEST_P(AlgorithmTests, bubbleSort) {
    vector<int> nums = GetParam();
    Algorithm::bubbleSort(nums);
    EXPECT_TRUE(Utils::isOrderly(nums, true));
}

TEST_P(AlgorithmTests, selectSort) {
    vector<int> nums = GetParam();
    Algorithm::selectSort(nums);
    EXPECT_TRUE(Utils::isOrderly(nums, true));
}

TEST_P(AlgorithmTests, heapSort) {
    vector<int> nums = GetParam();
    Algorithm::heapSort(nums);
    EXPECT_TRUE(Utils::isOrderly(nums, true));
}

INSTANTIATE_TEST_SUITE_P(sort, AlgorithmTests,
                         ::testing::Values(
                                 vector<int>{6, 1, 2, 7, 9, 11, 5, 4, 3, 10, 8},
                                 vector<int>{6, 7, 8, 9, 10},
                                 vector<int>{5, 4, 3, 2, 1},
                                 vector<int>{3, 1}));