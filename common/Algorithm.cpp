#include "Algorithm.h"

void quickSortInternal(std::vector<int> &elements, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = elements[start];
    int left = start;
    int right = end;
    while (left < right) {
        while (elements[right] > pivot && left < right) {
            right--;
        }
        elements[left] = elements[right];
        while (elements[left] <= pivot && left < right) {
            left++;
        }
        elements[right] = elements[left];
    }
    elements[left] = pivot;
    quickSortInternal(elements, start, left - 1);
    quickSortInternal(elements, left + 1, end);
}

void Algorithm::quickSort(std::vector<int> &elements) {
    if (elements.empty()) {
        return;
    }
    quickSortInternal(elements, 0, (int)elements.size() - 1);
}
