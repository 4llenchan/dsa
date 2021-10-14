#ifndef DSA_ALGORITHM_H
#define DSA_ALGORITHM_H

#include <vector>

class Algorithm {
public:
    static void quickSort(std::vector<int> &nums);

    static void mergeSort(std::vector<int> &nums);

    static void insertSort(std::vector<int> &nums);

    static void bubbleSort(std::vector<int> &nums);

    static void selectSort(std::vector<int> &nums);
};

#endif // DSA_ALGORITHM_H
