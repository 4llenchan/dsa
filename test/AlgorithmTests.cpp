#include <gtest/gtest.h>
#include <vector>
#include "Algorithm.h"

using namespace std;

class AlgorithmTests : public ::testing::TestWithParam<vector<int>> {

};

TEST_P(AlgorithmTests, quickSort) {
    vector<int> elements = GetParam();
    Algorithm::quickSort(elements);
    if (!elements.empty()) {
        int last = elements[0];
        for (int &element: elements) {
            EXPECT_GE(element, last);
            last = element;
        }
    }
}

INSTANTIATE_TEST_SUITE_P(sort, AlgorithmTests,
                         ::testing::Values(
                                 vector<int>{6, 1, 2, 7, 9, 11, 5, 4, 3, 10, 8},
                                 vector<int>{6, 7, 8, 9, 10},
                                 vector<int>{5, 4, 3, 2, 1}
                         ));