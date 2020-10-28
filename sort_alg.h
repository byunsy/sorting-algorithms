#ifndef SORT_ALG_H_INCLUDED
#define SORT_ALG_H_INCLUDED

// 01. INSERTION SORT
void InsertionSort(int *arr, int arr_size);

// 02. SELECTION SORT
void swap(int &a, int &b);
void SelectionSort(int *arr, int size);

// 03. MERGE SORT
void Merge(int *array, int l, int m, int r);
void MergeSort(int *array, int l, int r);

// 04. QUICK SORT
int partition(int *arr, int low, int high);
void QuickSort(int *arr, int low, int high);

// 05. HEAP SORT
void heapify(int *arr, int heap_size, int root_idx);
void HeapSort(int arr[], int n);

// 06. SHELL SORT
void ShellSort(int *arr, int arr_size);

// 07. BUBBLE SORT
void BubbleSort(int *arr, int arr_size);

#endif