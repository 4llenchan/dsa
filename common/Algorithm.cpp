#include "Algorithm.h"

void quickSortInternal(std::vector<int> &nums, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = nums[start];
    int left = start;
    int right = end;
    while (left < right) {
        while (nums[right] > pivot && left < right) {
            right--;
        }
        nums[left] = nums[right];
        while (nums[left] <= pivot && left < right) {
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    quickSortInternal(nums, start, left - 1);
    quickSortInternal(nums, left + 1, end);
}

void Algorithm::quickSort(std::vector<int> &nums) {
    if (nums.empty()) {
        return;
    }
    quickSortInternal(nums, 0, (int)nums.size() - 1);
}

/**
 * merge sort within [l, r)
 *
 * @param nums array to sort
 * @param l start index, include
 * @param r end index, not include
 * @param tmp array to store middle result
 */
void mergeSortInternal(std::vector<int> &nums, int l, int r, std::vector<int> &tmp) {
    if (l + 1 >= r) {
        return;
    }
    int m = (l + r) / 2;
    mergeSortInternal(nums, l, m, tmp);
    mergeSortInternal(nums, m, r, tmp);
    int p = l;
    int q = m;
    int i = l;
    while (p < m || q < r) {
        if (q >= r || (p < m && nums[p] <= nums[q])) {
            tmp[i++] = nums[p++];
        } else {
            tmp[i++] = nums[q++];
        }
    }
    for (i = l; i < r; ++i) {
        nums[i] = tmp[i];
    }
}

void Algorithm::mergeSort(std::vector<int> &nums) {
    int n = (int)nums.size();
    if (n <= 1) {
        return;
    }
    std::vector<int> tmp(n);
    mergeSortInternal(nums, 0, n, tmp);
}

void Algorithm::insertSort(std::vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
            std::swap(nums[j], nums[j - 1]);
        }
    }
}

void Algorithm::bubbleSort(std::vector<int> &nums) {
    int n = (int)nums.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
            }
        }
    }
}

void Algorithm::selectSort(std::vector<int> &nums) {
    int n = (int)nums.size();
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[k]) {
                k = j;
            }
        }
        std::swap(nums[k], nums[i]);
    }
}
