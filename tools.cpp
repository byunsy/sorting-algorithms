#include "tools.h"

#include <cstring>
#include <iomanip>
#include <iostream>

void PrintArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(4) << arr[i] << " ";

        // Print ten items per line
        if ((i + 1) % 15 == 0) {
            std::cout << "\n";
        }
    }
    std::cout << "\n\n";
}

void PrintHeader(int sort) {
    // Print a simple line
    for (int i = 0; i < 80; i++) {
        std::cout << "=";
    }
    std::cout << "\n";

    switch (sort) {
        case 0:
            std::cout << " ORIGINAL UNSORTED ARRAY\n";
            break;
        case 1:
            std::cout << " 01. INSERTION SORT\n";
            break;
        case 2:
            std::cout << " 02. SELECTION SORT\n";
            break;
        case 3:
            std::cout << " 03. MERGE SORT\n";
            break;
        case 4:
            std::cout << " 04. QUICK SORT\n";
            break;
        case 5:
            std::cout << " 05. HEAP SORT\n";
            break;
        case 6:
            std::cout << " 06. SHELL SORT\n";
            break;
        case 7:
            std::cout << " 07. BUBBLE SORT\n";
            break;

        default:
            break;
    }
    // Print another simple line
    for (int i = 0; i < 80; i++) {
        std::cout << "=";
    }
    std::cout << "\n";
}

int* CreateRandomArray(int size) {
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    return arr;
}