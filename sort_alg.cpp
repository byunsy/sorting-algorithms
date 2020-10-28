#include "sort_alg.h"

#include <cstring>
#include <iostream>

#include "tools.h"

// ============================================================================
// 01. INSERTION SORT
// ============================================================================
void InsertionSort(int *arr, int arr_size) {
    int cur;   // current index
    int key;   // current item
    int prev;  // previous index

    // traverse through each item of a given array
    for (cur = 1; cur < arr_size; cur++) {
        key = arr[cur];  // current item
        prev = cur - 1;  // previous index

        // when prev > curr
        while (prev >= 0 && arr[prev] > key) {
            // curr is now prev
            arr[prev + 1] = arr[prev];

            // decrement prev index
            prev = prev - 1;
        }
        // when curr > prev
        arr[prev + 1] = key;
    }
}

// ============================================================================
// 02. SELECTION SORT
// ============================================================================
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int *arr, int arr_size) {
    int first;  // first index
    int cur;    // current index
    int min;    // index of minimum item in the array

    // resizing the unsorted array
    for (first = 0; first < arr_size - 1; first++) {
        // index of min is initially the first index of unsorted array
        min = first;

        // traverse through each item of unsorted array
        for (cur = first + 1; cur < arr_size; cur++) {
            // if current item < min item
            if (arr[cur] < arr[min]) {
                // update the index of min
                min = cur;
            }
        }
        // swap the min item to the beginning of array
        swap(arr[first], arr[min]);
    }
}

// ============================================================================
// 03. MERGE SORT
// ============================================================================
void merge(int *arr, int l, int m, int r) {
    int i, j, k, l_size, r_size;

    // size of left and right sub-arrays
    l_size = m - l + 1;
    r_size = r - m;

    // create temporary sub-arrays
    int l_arr[l_size], r_arr[r_size];

    // copy and fill left and right sub-arrays
    for (i = 0; i < l_size; i++) {
        l_arr[i] = arr[l + i];
    }

    for (j = 0; j < r_size; j++) {
        r_arr[j] = arr[m + 1 + j];
    }

    i = 0;  // index of left sub-array
    j = 0;  // index of right sub-array
    k = l;  // index of merged sorted array

    // Merge  sub-arrays to sorted array
    while (i < l_size && j < r_size) {
        if (l_arr[i] <= r_arr[j]) {
            arr[k] = l_arr[i];
            i++;
        } else {
            arr[k] = r_arr[j];
            j++;
        }
        k++;
    }
    while (i < l_size) {  // extra element in left array
        arr[k] = l_arr[i];
        i++;
        k++;
    }
    while (j < r_size) {  // extra element in right array
        arr[k] = r_arr[j];
        j++;
        k++;
    }
}

void MergeSort(int *arr, int l, int r) {
    if (l < r) {
        // Calculate middle
        int m = l + (r - l) / 2;

        // Sort first and second arrays
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// ============================================================================
// 04. QUICK SORT
// ============================================================================
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    return (i + 1);
}

void QuickSort(int *arr, int low, int high) {
    if (low < high) {
        int partition_index = partition(arr, low, high);
        QuickSort(arr, low, partition_index - 1);
        QuickSort(arr, partition_index + 1, high);
    }
};

// ============================================================================
// 05. HEAP SORT
// ============================================================================
// heapify() finds max node from given root node and its two children
void heapify(int *arr, int heap_size, int root_idx) {
    int max_idx = root_idx;
    int lchild_idx = 2 * root_idx + 1;
    int rchild_idx = 2 * root_idx + 2;

    if (lchild_idx < heap_size && arr[lchild_idx] > arr[max_idx]) {
        max_idx = lchild_idx;
    }

    if (rchild_idx < heap_size && arr[rchild_idx] > arr[max_idx]) {
        max_idx = rchild_idx;
    }

    // Swap and continue heapifying if root is not largest
    if (max_idx != root_idx) {
        swap(arr[root_idx], arr[max_idx]);
        heapify(arr, heap_size, max_idx);
    }
}

void HeapSort(int arr[], int arr_size) {
    // 1. Build max heap (rearrange array)
    for (int i = (arr_size / 2 - 1); i >= 0; i--) {
        heapify(arr, arr_size, i);
    }

    // 2. One by one extract an element from heap
    for (int i = (arr_size - 1); i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// ============================================================================
// 06. SHELL SORT
// ============================================================================
void ShellSort(int *arr, int arr_size) {
    // Gradually reduce the gap by half each time
    for (int gap = arr_size / 2; gap > 0; gap /= 2) {
        // Traverse through the array using gap
        for (int i = gap; i < arr_size; i += 1) {
            // save in a temp variable
            int temp = arr[i];

            int j;
            // Check items less than arr[i] in gap interval
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // Place the saved item in this position
            arr[j] = temp;
        }
    }
}

// ============================================================================
// 07. BUBBLE SORT
// ============================================================================
void BubbleSort(int *arr, int arr_size) {
    // Repeat until array is sorted
    while (true) {
        int swapped = 0;
        // Traverse through the array to swap if necessary
        for (int cur = 1; cur < arr_size; cur++) {
            int prev = cur - 1;

            if (arr[prev] > arr[cur]) {
                swap(arr[prev], arr[cur]);
                swapped++;
            }
        }
        // If not swapped at all, the array is now sorted
        if (swapped == 0) {
            break;
        }
    }
}