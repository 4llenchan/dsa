#include "Algorithm.h"

void quickSortInternal(std::vector<int> &elements, int left, int right) {

}

void Algorithm::quickSort(std::vector<int> &elements) {
    if (elements.empty()) {
        return;
    }
    int pivot = elements[0];
    int left = 1;
    int right = (int)elements.size() - 1;
    while (left < right && elements[right] > pivot) {
        right--;
    }
    while (left < right && elements[left] <= pivot) {
        left++;
    }
    std::swap(elements[left], elements[right]);
    left++;
    right--;

}
