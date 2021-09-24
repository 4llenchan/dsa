#include "Algorithm.h"

void quickSortInternal(std::vector<int> &elements, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = elements[start];
    int left = start + 1;
    int right = end;
    while (left < right) {
        while (elements[right] > pivot && left < right) {
            right--;
        }
        while (elements[left] <= pivot && left < right) {
            left++;
        }
        std::swap(elements[left], elements[right]);
    }
    if (elements[right] < pivot) {
        std::swap(elements[start], elements[right]);
    } else {
        right--;
    }
    quickSortInternal(elements, start, left - 1);
    quickSortInternal(elements, right + 1, end);
}

void Algorithm::quickSort(std::vector<int> &elements) {
    if (elements.empty()) {
        return;
    }
    quickSortInternal(elements, 0, (int)elements.size() - 1);
}
