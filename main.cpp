#include <chrono>
#include <cstring>
#include <iostream>

#include "sort_alg.h"
#include "tools.h"

// ============================================================================
//                                     MAIN
// ============================================================================
int main(void) {
    const int size = 1000;
    const int rep = 1000;

    // ========================================================================
    // 01. INSERTION SORT
    // ========================================================================
    PrintHeader(1);

    auto duration1 = 0;

    for (int i = 0; i < rep; i++) {
        int *arr1 = CreateRandomArray(size);

        // Print the unsorted randomized array (just once)
        if (i == 0) {
            PrintArray(arr1, size);
        }

        // Timer start point
        const auto t1 = std::chrono::high_resolution_clock::now();

        InsertionSort(arr1, size);

        // Timer end point
        const auto t2 = std::chrono::high_resolution_clock::now();

        // Calculate performance time
        duration1 +=
            std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                .count();

        // Print the result, the sorted array (just once)
        if (i == 0) {
            PrintArray(arr1, size);
        }

        delete[] arr1;
    }

    std::cout << " Performance Time: " << duration1 / rep
              << " microseconds.\n\n";  // Average duration

    //========================================================================
    // 02. SELECTION SORT
    //========================================================================
    PrintHeader(2);

    auto duration2 = 0;

    for (int i = 0; i < rep; i++) {
        int *arr2 = CreateRandomArray(size);

        // Print the unsorted randomized array (just once)
        if (i == 0) {
            PrintArray(arr2, size);
        }

        // Timer start point
        const auto t1 = std::chrono::high_resolution_clock::now();

        SelectionSort(arr2, size);

        // Timer end point
        const auto t2 = std::chrono::high_resolution_clock::now();

        // Calculate performance time
        duration2 +=
            std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                .count();

        // Print the result, the sorted array (just once)
        if (i == 0) {
            PrintArray(arr2, size);
        }

        delete[] arr2;
    }

    std::cout << " Performance Time: " << duration2 / rep
              << " microseconds.\n\n";  // Average duration

    //========================================================================
    // 03. MERGE SORT
    //========================================================================
    PrintHeader(3);

    auto duration3 = 0;

    for (int i = 0; i < rep; i++) {
        int *arr3 = CreateRandomArray(size);

        // Print the unsorted randomized array (just once)
        if (i == 0) {
            PrintArray(arr3, size);
        }

        // Timer start point
        const auto t1 = std::chrono::high_resolution_clock::now();

        MergeSort(arr3, 0, size - 1);

        // Timer end point
        const auto t2 = std::chrono::high_resolution_clock::now();

        // Calculate performance time
        duration3 +=
            std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                .count();

        // Print the result, the sorted array (just once)
        if (i == 0) {
            PrintArray(arr3, size);
        }

        delete[] arr3;
    }

    std::cout << " Performance Time: " << duration3 / rep
              << " microseconds.\n\n";  // Average duration

    //========================================================================
    // 04. QUICK SORT
    //========================================================================
    PrintHeader(4);

    auto duration4 = 0;

    for (int i = 0; i < rep; i++) {
        int *arr4 = CreateRandomArray(size);

        // Print the unsorted randomized array (just once)
        if (i == 0) {
            PrintArray(arr4, size);
        }

        // Timer start point
        const auto t1 = std::chrono::high_resolution_clock::now();

        QuickSort(arr4, 0, size - 1);

        // Timer end point
        const auto t2 = std::chrono::high_resolution_clock::now();

        // Calculate performance time
        duration4 +=
            std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                .count();

        // Print the result, the sorted array (just once)
        if (i == 0) {
            PrintArray(arr4, size);
        }

        delete[] arr4;
    }

    std::cout << " Performance Time: " << duration4 / rep
              << " microseconds.\n\n";  // Average duration

    //========================================================================
    // 05. HEAP SORT
    //========================================================================
    PrintHeader(5);

    auto duration5 = 0;

    for (int i = 0; i < rep; i++) {
        int *arr5 = CreateRandomArray(size);

        // Print the unsorted randomized array (just once)
        if (i == 0) {
            PrintArray(arr5, size);
        }

        // Timer start point
        const auto t1 = std::chrono::high_resolution_clock::now();

        HeapSort(arr5, size);

        // Timer end point
        const auto t2 = std::chrono::high_resolution_clock::now();

        // Calculate performance time
        duration5 +=
            std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                .count();

        // Print the result, the sorted array (just once)
        if (i == 0) {
            PrintArray(arr5, size);
        }

        delete[] arr5;
    }

    std::cout << " Performance Time: " << duration5 / rep
              << " microseconds.\n\n";  // Average duration

    //========================================================================
    // 06. SHELL SORT
    //========================================================================
    PrintHeader(6);

    auto duration6 = 0;

    for (int i = 0; i < rep; i++) {
        int *arr6 = CreateRandomArray(size);

        // Print the unsorted randomized array (just once)
        if (i == 0) {
            PrintArray(arr6, size);
        }

        // Timer start point
        const auto t1 = std::chrono::high_resolution_clock::now();

        ShellSort(arr6, size);

        // Timer end point
        const auto t2 = std::chrono::high_resolution_clock::now();

        // Calculate performance time
        duration6 +=
            std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                .count();

        // Print the result, the sorted array (just once)
        if (i == 0) {
            PrintArray(arr6, size);
        }

        delete[] arr6;
    }

    std::cout << " Performance Time: " << duration6 / rep
              << " microseconds.\n\n";  // Average duration

    //========================================================================
    // 07. BUBLLE SORT
    //========================================================================
    PrintHeader(7);

    auto duration7 = 0;

    for (int i = 0; i < rep; i++) {
        int *arr7 = CreateRandomArray(size);

        // Print the unsorted randomized array (just once)
        if (i == 0) {
            PrintArray(arr7, size);
        }

        // Timer start point
        const auto t1 = std::chrono::high_resolution_clock::now();

        BubbleSort(arr7, size);

        // Timer end point
        const auto t2 = std::chrono::high_resolution_clock::now();

        // Calculate performance time
        duration7 +=
            std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1)
                .count();

        // Print the result, the sorted array (just once)
        if (i == 0) {
            PrintArray(arr7, size);
        }

        delete[] arr7;
    }

    std::cout << " Performance Time: " << duration7 / rep
              << " microseconds.\n\n";  // Average duration

    return 0;
}