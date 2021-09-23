#include <gtest/gtest.h>
#include <vector>
#include "Algorithm.h"

using namespace std;

class AlgorithmTests : public ::testing::Test {

};

TEST_F(AlgorithmTests, quickSort) {
    vector<int> elements{6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    Algorithm::quickSort(elements);
    for (int i = 0; i < elements.size(); ++i) {
        EXPECT_EQ(elements[i], i + 1);
    }
}